#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int M = 3e5 + 5;
const int SN = 1 << 20;
int n;
int arrl[N];
int arrv[N];
int arrr[N];
vector < int > v[M];
int ansl , ansv , ansr;
pair < int , int > segtree[SN];
int lazy[SN];
void build(int l , int r , int node){
    segtree[node] = make_pair(0 , r);
    lazy[node] = 0;
    if(l < r){
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
    }
}
void push(int l , int r , int node){
    if(lazy[node]){
        segtree[node].first += lazy[node];
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
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d %d" , arrl + i , arrv + i , arrr + i);
        v[arrl[i]].emplace_back(i);
        v[arrv[i]].emplace_back(-i);
    }
    ansl = -1;
    ansr = -1;
    ansv = 0;
    build(1 , M - 1 , 1);
    for(int i = 1 ; i < M ; ++i){
        for(int idx : v[i]){
            if(idx > 0){
                update(1 , M - 1 , 1 , arrv[idx] , arrr[idx] , 1);
            }
        }
        if(segtree[1].first > ansv){
            ansv = segtree[1].first;
            ansl = i;
            ansr = segtree[1].second;
        }
        for(int idx : v[i]){
            if(idx < 0){
                update(1 , M - 1 , 1 , arrv[-idx] , arrr[-idx] , -1);
            }
        }
    }
    printf("%d\n" , ansv);
    for(int i = 1 ; i <= n ; ++i){
        if(arrl[i] <= ansl && arrr[i] >= ansr && arrv[i] >= ansl && arrv[i] <= ansr){
            printf("%d " , i);
        }
    }
    printf("\n");
}