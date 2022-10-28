#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
int n;
int p[N] , t[N];
int x[N];
int arr[N];
int segtree[SN];
int lazy[SN];
void push(int l , int r , int node){
    if(lazy[node]){
        segtree[node] += lazy[node];
        if(l != r){
            lazy[node + node] += lazy[node];
            lazy[node + node + 1] += lazy[node];
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
    segtree[node] = max(segtree[node + node] , segtree[node + node + 1]);
}
int query(int l , int r , int node){
    push(l , r , node);
    if(segtree[node] <= 0){
        return -1;
    }
    if(l == r){
        return arr[l];
    }
    int mid = l + r >> 1;
    int ret = query(mid + 1 , r , node + node + 1);
    if(ret == -1){
        ret = query(l , mid , node + node);
    }
    return ret;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , p + i , t + i);
        if(t[i] == 0){
            update(1 , n , 1 , 1 , p[i] , -1);
        }
        else{
            scanf("%d" , x + i);
            arr[p[i]] = x[i];
            update(1 , n , 1 , 1 , p[i] , 1);
        }
        printf("%d\n" , query(1 , n , 1));
    }
}