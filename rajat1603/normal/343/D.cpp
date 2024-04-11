#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n;
int q;
vector < int > v[N];
int start[N];
int finish[N];
int timer = 0;
void dfs(int node , int parent){
    start[node] = ++timer;
    for(auto it : v[node]){
        if(it != parent){
            dfs(it , node);
        }
    }
    finish[node] = timer;
}
int segtree[1 << 20] = {0};
int segtree2[1 << 20];
void update(int l , int r , int node , int ql , int qr , int val){
    if(l > qr || r < ql){
        return;
    }
    if(l >= ql && r <= qr){
        segtree[node] = val;
        return;
    }
    int mid = (l + r) >> 1;
    int lc = node + node;
    int rc = lc | 1;
    update(l , mid , lc , ql , qr , val);
    update(mid + 1 , r , rc , ql , qr , val);
}
int query(int idx){
    int node = 1;
    int l = 1;
    int r = n;
    int ret = segtree[1];
    while(l ^ r){
        int mid = (l + r) >> 1;
        node += node;
        if(mid >= idx){
            r = mid;
        }
        else{
            l = mid + 1;
            ++node;
        }
        ret = max(ret , segtree[node]);
    }
    return ret;
}
void update(int l , int r , int node , int idx , int val){
    if(l == r){
        segtree2[node] = val;
        return ;
    }
    int mid = (l + r) >> 1;
    int lc = node + node;
    int rc = lc | 1;
    if(mid >= idx){
        update(l , mid , lc , idx , val);
    }
    else{
        update(mid + 1 , r , rc , idx , val);
    }
    segtree2[node] = max(segtree2[lc] , segtree2[rc]);
}
int query(int l , int r , int node , int ql , int qr){
    if(l > qr || r < ql){
        return 0;
    }
    if(l >= ql && r <= qr){
        return segtree2[node];
    }
    int mid = (l + r) >> 1;
    int lc = node + node;
    int rc = lc | 1;
    return max(query(l , mid , lc , ql , qr) , query(mid + 1 , r , rc , ql , qr));
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i < n ; ++i){
        int a , b;
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    dfs(1 , -1);
    scanf("%d" , &q);
    for(int i = 1 ; i <= q ; ++i){
        int type , node;
        scanf("%d %d" , &type , &node);
        if(type == 1){
            update(1 , n , 1 , start[node] , finish[node] , i);
        }
        else if(type == 2){
            update(1 , n , 1 , start[node] , i);
        }
        else{
            int idx1 = query(start[node]);
            int idx2 = query(1 , n , 1 , start[node] , finish[node]);
            printf("%d\n" , idx1 > idx2);
        }
    }
}