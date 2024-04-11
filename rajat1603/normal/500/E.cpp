#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int SZ = 1e9 + 9;
struct node{
    int val;
    bool lazy;
    node* left;
    node* right;
    node(int l , int r){
        val = r - l + 1;
        lazy = 0;
        left = NULL;
        right = NULL;
    }
    void push(int l , int r){
        if(lazy && val){
            val = 0;
            if(l != r){
                int mid = l + r >> 1;
                if(left == NULL){
                    left = new node(l , mid);
                }
                if(right == NULL){
                    right = new node(mid + 1 , r);
                }
                left -> lazy = 1;
                right -> lazy = 1;
            }
        }
    }
    node* update(int l , int r , int ql , int qr){
        push(l , r);
        if(l > qr || r < ql || !val){
            return this;
        }
        if(l >= ql && r <= qr){
            lazy = 1;
            push(l , r);
            return this;
        }
        int mid = l + r >> 1;
        if(left == NULL){
            left = new node(l , mid);
        }
        if(right == NULL){
            right = new node(mid + 1 , r);
        }
        left = left -> update(l , mid , ql , qr);
        right = right -> update(mid + 1 , r , ql , qr);
        val = left -> val + right -> val;
        return this;
    }
    int query(int l , int r , int ql , int qr){
        push(l , r);
        if(l > qr || r < ql || !val || lazy){
            return 0;
        }
        if(l >= ql && r <= qr){
            return val;
        }
        int mid = l + r >> 1;
        if(left == NULL){
            left = new node(l , mid);
        }
        if(right == NULL){
            right = new node(mid + 1 , r);
        }
        return left -> query(l , mid , ql , qr) + right -> query(mid + 1 , r , ql , qr);
    }
};
node* root = new node(1 , SZ);
int n , q;
int p[N];
int l[N];
int ans[N];
vector < pair < int , int > > Q[N];
int x , y;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , p + i , l + i);
    }
    scanf("%d" , &q);
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d %d" , &x , &y);
        Q[x].emplace_back(make_pair(y , i));
    }
    for(int i = n ; i >= 1 ; --i){
        root = root -> update(1 , SZ , p[i] , min(SZ , p[i] + l[i] - 1));
        for(auto it : Q[i]){
            ans[it.second] = root -> query(1 , SZ , p[i] , p[it.first] - 1);
        }
    }
    for(int i = 1 ; i <= q ; ++i){
        printf("%d\n" , ans[i]);
    }
}