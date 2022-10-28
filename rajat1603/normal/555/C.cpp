#include "bits/stdc++.h"
using namespace std;
int mx;
struct node{
    int val;
    node* left;
    node* right;
    node(){
        val = 0;
        left = NULL;
        right = NULL;
    }
    node* insert(int l , int r , int num , int ql , int qr){
        if(l > qr || r < ql || val > num){
            return this;
        }
        if(l >= ql && r <= qr){
            val = max(val , num);
            return this;
        }
        int mid = l + r >> 1;
        if(left == NULL){
            left = new node();
        }
        if(right == NULL){
            right = new node();
        }
        left = left -> insert(l , mid , num , ql , qr);
        right = right -> insert(mid + 1 , r , num , ql , qr);
        return this;
    }
    void query(int l , int r , int idx){
        mx = max(mx , val);
        int mid = l + r >> 1;
        if(idx <= mid){
            if(left != NULL){
                left -> query(l , mid , idx);
            }
        }
        else{
            if(right != NULL){
                right -> query(mid + 1 , r , idx);
            }
        }
    }
};
node* root1 = new node();
node* root2 = new node();
int n , q;
int x , y;
char dir;
set < int > s1 , s2;
int main(){
    cin >> n >> q;
    while(q--){
        mx = 0;
        cin >> y >> x >> dir;
        if(dir == 'U'){
            root2 -> query(1 , n , y);
            if(s1.find(x) != s1.end()){
                mx = x;
            }
            s1.insert(x);
            printf("%d\n" , x - mx);
            if(mx < x)
                root1 = root1 -> insert(1 , n , y , mx + 1 , x);
        }
        else{
            root1 -> query(1 , n , x);
            if(s2.find(x) != s2.end()){
                mx = y;
            }
            s2.insert(x);
            printf("%d\n" , y - mx);
            if(mx < y){
                root2 = root2 -> insert(1 , n , x , mx + 1 , y);
            }
        }
    }
}