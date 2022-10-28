#include "bits/stdc++.h"
using namespace std;
const int N = 4e5 + 5;
const int SN = 1 << 20;
int n , m;
int arr[N];
vector < int > v[N];
int start[N];
int finish[N];
int rev[N];
int timer = 0;
int a , b;
int type , qnode , col;
void dfs(int node , int parent){
    start[node] = ++timer;
    rev[timer] = node;
    for(int next : v[node]){
        if(next != parent){
            dfs(next , node);
        }
    }
    finish[node] = timer;
}
long long segtree[SN];
int lazy[SN];
void build(int l , int r , int node){
    lazy[node] = 0;
    if(l == r){
        segtree[node] = 1LL << arr[rev[l]];
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        segtree[node] = segtree[node + node] | segtree[node + node + 1];
    }
}
void push(int l , int r , int node){
    if(lazy[node]){
        segtree[node] = 1LL << lazy[node];
        if(l != r){
            lazy[node + node] = lazy[node];
            lazy[node + node + 1] = lazy[node];
        }
        lazy[node] = 0;
    }
}
void update(int l , int r , int node , int ql , int qr , int val){
    push(l , r , node);
    if(l > qr || r < ql){
        return;
    }
    if(l >= ql && r <= qr){
        lazy[node] = val;
        push(l , r , node);
        return;
    }
    int mid = l + r >> 1;
    update(l , mid , node + node , ql , qr , val);
    update(mid + 1 , r , node + node + 1 , ql , qr , val);
    segtree[node] = segtree[node + node] | segtree[node + node + 1];
}
long long query(int l , int r , int node , int ql , int qr){
    push(l , r , node);
    if(l > qr || r < ql){
        return 0LL;
    }
    if(l >= ql && r <= qr){
        return segtree[node];
    }
    int mid = l + r >> 1;
    return query(l , mid , node + node , ql , qr) | query(mid + 1 , r , node + node + 1 , ql , qr);
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    dfs(1 , 0);
    build(1 , n , 1);
    while(m--){
        scanf("%d %d" , &type , &qnode);
        if(type == 1){
            scanf("%d" , &col);
            update(1 , n , 1 , start[qnode] , finish[qnode] , col);
        }
        else{
            printf("%d\n" , __builtin_popcountll(query(1 , n , 1 , start[qnode] , finish[qnode])));
        }
    }
}