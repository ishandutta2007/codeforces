#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int M = 1e4 + 4;
const int SN = 1 << 18;
const int precalc[] = {4 , 7 , 44 , 47 , 74 , 77 , 444 , 447 , 474 , 477 , 744 , 747 , 774 , 777 , 4444 , 4447 , 4474 , 4477 , 4744 , 4747 , 4774 , 4777 , 7444 , 7447 , 7474 , 7477 , 7744 , 7747 , 7774 , 7777};
int nxt[M];
int n , q;
int arr[N];
char que[10];
int ql , qr , qd;
int segtree[SN];
int minimum[SN];
int lazy[SN];
void build(int l , int r , int node){
    lazy[node] = 0;
    if(l == r){
        minimum[node] = nxt[arr[l]];
        segtree[node] = !minimum[node];
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        minimum[node] = min(minimum[node + node] , minimum[node + node + 1]);
        segtree[node] = segtree[node + node] + segtree[node + node + 1];
    }
}
void push(int l , int r , int node){
    if(lazy[node]){
        if(lazy[node] >= minimum[node]){
            if(l == r){
                arr[l] += lazy[node];
                minimum[node] = nxt[arr[l]];
                segtree[node] = !minimum[node];
            }
            else{
                lazy[node + node] += lazy[node];
                lazy[node + node + 1] += lazy[node];
                push(l , l + r >> 1 , node + node);
                push(l + r + 2 >> 1 , r , node + node + 1);
                minimum[node] = min(minimum[node + node] , minimum[node + node + 1]);
                segtree[node] = segtree[node + node] + segtree[node + node + 1];
            }
        }
        else{
            minimum[node] -= lazy[node];
            if(l != r){
                lazy[node + node] += lazy[node];
                lazy[node + node + 1] += lazy[node];
            }
            else{
                arr[l] += lazy[node];
            }
        }
        lazy[node] = 0;
    }
}
void update(int l , int r , int node , int ql , int qr , int add){
    push(l , r , node);
    if(l > qr || r < ql){
        return;
    }
    if(l >= ql && r <= qr){
        lazy[node] += add;
        push(l , r , node);
        return;
    }
    int mid = l + r >> 1;
    update(l , mid , node + node , ql , qr , add);
    update(mid + 1 , r , node + node + 1 , ql , qr , add);
    minimum[node] = min(minimum[node + node] , minimum[node + node + 1]);
    segtree[node] = segtree[node + node] + segtree[node + node + 1];
}
int query(int l , int r , int node , int ql , int qr){
    push(l , r , node);
    if(l > qr || r < ql){
        return 0;
    }
    if(l >= ql && r <= qr){
        return segtree[node];
    }
    int mid = l + r >> 1;
    int res = query(l , mid , node + node , ql , qr) + query(mid + 1 , r , node + node + 1 , ql , qr);
    minimum[node] = min(minimum[node + node] , minimum[node + node + 1]);
    segtree[node] = segtree[node + node] + segtree[node + node + 1];
    return res;
}
int main(){
    for(int i = 0 ; i < M ; ++i){
        nxt[i] = 1e9;
    }
    for(int i : precalc){
        nxt[i] = 0;
    }
    for(int i = M - 2 ; i >= 0 ; --i){
        nxt[i] = min(nxt[i] , nxt[i + 1] + 1);
    }
    scanf("%d %d" , &n , &q);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    build(1 , n , 1);
    while(q--){
        scanf("%s %d %d" , que , &ql , &qr);
        if(que[0] == 'c'){
            printf("%d\n" , query(1 , n , 1 , ql , qr));
        }
        else{
            scanf("%d" , &qd);
            update(1 , n , 1 , ql , qr , qd);
        }
    }
}