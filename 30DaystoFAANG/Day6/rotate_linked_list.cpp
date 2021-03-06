/* Problem Link => https://leetcode.com/problems/rotate-list/ */

/* Good approach but TLE as it traveses the whole thing again and again */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }
        while(k--){
            ListNode *tail = head;
            ListNode *prev = head;
            while(tail->next != NULL){
                prev = tail;
                tail = tail->next;
            }
            
            prev->next = NULL;
            tail->next = head;
            head = tail;
        }
        
        //cout<<tail->val;
        return head;
    }
};

/* Efficient approach after a little modification */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }
        int n = 1;
        ListNode *tail = head;
        while(tail->next != NULL){
            tail = tail->next;
            n++;
        }
        
        //tail->next = head;
        
        int toChange = k%n;
        
        while(toChange--){
            ListNode *tail = head;
            ListNode *prev = head;
            while(tail->next != NULL){
                prev = tail;
                tail = tail->next;
            }
            
            prev->next = NULL;
            tail->next = head;
            head = tail;
        }
        cout<<n;
        //cout<<tail->val;
        return head;
    }
};
