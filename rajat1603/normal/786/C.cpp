#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 19;
struct node{
    int val;
    int left;
    int right;
    node(){
        val = 0;
        left = 0;
        right = 0;
    }
};
node st[N * LN * 2];
int root[N];
int cur;
int dummy;
void init(){
    cur = 0;
    dummy = 0;
    st[dummy].left = dummy;
    st[dummy].right = dummy;
    st[dummy].val = 0;
}
inline int newnode(int val , int left , int right){
    ++cur;
    st[cur].val = val;
    st[cur].left = left;
    st[cur].right = right;
    return cur;
}
inline void insert(int &curnode , int prenode , int l , int r , int idx , int value){
    if(l == r){
        curnode = newnode(st[prenode].val + value , dummy , dummy);
        return;
    }
    int mid = l + r >> 1;
    if(idx <= mid){
        curnode = newnode(st[prenode].val + value , dummy , st[prenode].right);
        insert(st[curnode].left , st[prenode].left , l , mid , idx , value);
    }
    else{
        curnode = newnode(st[prenode].val + value , st[prenode].left , dummy);
        insert(st[curnode].right , st[prenode].right , mid + 1 , r , idx , value);
    }
}
int n;
int arr[N];
int last[N];
void build(){
    init();
    root[0] = dummy;
    for(int i = 1 ; i <= n ; ++i){
        root[i] = root[i - 1];
        if(last[arr[i]]){
            insert(root[i] , root[i] , 1 , n , last[arr[i]] , -1);
            insert(root[i] , root[i] , 1 , n , i , 1);
        }
        else{
            insert(root[i] , root[i] , 1 , n , i , 1);
        }
        last[arr[i]] = i;
    }
}
inline int find(int idx , int k){
    int l = 1;
    int r = n;
    int node = root[idx];
    if(st[node].val <= k){
        return 0;
    }
    while(l < r){
        int mid = l + r >> 1;
        if(st[st[node].right].val > k){
            l = mid + 1;
            node = st[node].right;
        }
        else{
            k -= st[st[node].right].val;
            r = mid;
            node = st[node].left;
        }
    }
    return l;
}
void solve(int k){
    int ans = 0;
    int i = n;
    while(i > 0){
        i = find(i , k);
        ++ans;
    }
    printf("%d%c" , ans , " \n"[k == n]);
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    build();
    for(int k = 1 ; k <= n ; ++k){
        solve(k);
    }
}