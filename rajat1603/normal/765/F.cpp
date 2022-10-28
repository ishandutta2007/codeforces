#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int Q = 3e5 + 5;
const int LN = 32;
const int inf = 1e9 + 9;
const int SN = 1 << 18;
int n;
int arr[N];
int nxt1[N][LN];
int cur1[N];
int nxt2[N][LN];
int cur2[N];
int q;
int l[Q] , r[Q];
int ans[Q];
vector < int > v[N];
int bit[N];
int segtree[SN];
vector < int > req1[N];
vector < int > req2[N];
int lst[N];
int tmp[N];
int nxt[N];
int tp1[N];
int tp2[N];
int val[N];
int sz;
void build(int l , int r , int node){
    if(l == r){
        segtree[node] = lst[l];
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        segtree[node] = min(segtree[node + node] , segtree[node + node + 1]);
    }
}
void update(int l , int r , int node , int idx , int val){
    if(l == r){
        segtree[node] = val;
    }
    else{
        int mid = l + r >> 1;
        if(idx <= mid){
            update(l , mid , node + node , idx , val);
        }
        else{
            update(mid + 1 , r , node + node + 1 , idx , val);
        }
        segtree[node] = min(segtree[node + node] , segtree[node + node + 1]);
    }
}
int query(int l , int r , int node , int ql , int qr){
    if(l > qr || r < ql){
        return n + 1;
    }
    if(l >= ql && r <= qr){
        return segtree[node];
    }
    int mid = l + r >> 1;
    return min(query(l , mid , node + node , ql , qr) , query(mid + 1 , r , node + node + 1 , ql , qr));
}
void build(){
    sz = 0;
    for(int i = 1 ; i <= n ; ++i){
        tmp[++sz] = arr[i];
    }
    sort(tmp + 1 , tmp + 1 + sz);
    sz = unique(tmp + 1 , tmp + 1 + sz) - tmp - 1;
    for(int i = 1 ; i <= sz ; ++i){
        lst[i] = n + 1;
    }
    for(int i = n ; i >= 1 ; --i){
        val[i] = lower_bound(tmp + 1 , tmp + 1 + sz , arr[i]) - tmp;
        nxt[i] = lst[val[i]];
        lst[val[i]] = i;
    }
    build(1 , sz , 1);
    for(int i = 1 ; i <= n ; ++i){
        update(1 , sz , 1 , val[i] , nxt[i]);
        req1[i].emplace_back(i);
        req2[i].emplace_back(i);
        tp1[i] = sz;
        tp2[i] = 1;
        for(int idx : req1[i]){
            int l = val[idx];
            int r = tp1[idx];
            int j = query(1 , sz , 1 , l , r);
            if(j <= n){
                nxt1[idx][cur1[idx]++] = j;
                if(arr[j] != arr[idx]){
                    int mid = arr[idx] + arr[j] >> 1;
                    tp1[idx] = lower_bound(tmp + 1 , tmp + 1 + sz , mid + 1) - tmp - 1;
                    req1[j].emplace_back(idx);
                }
            }
        }
        for(int idx : req2[i]){
            int l = tp2[idx];
            int r = val[idx];
            int j = query(1 , sz , 1 , l , r);
            if(j <= n){
                nxt2[idx][cur2[idx]++] = j;
                if(arr[j] != arr[idx]){
                    int mid = arr[idx] + arr[j] >> 1;
                    tp2[idx] = lower_bound(tmp + 1 , tmp + 1 + sz , mid) - tmp;
                    req2[j].emplace_back(idx);
                }
            }
        }
    }
}
void update(int idx , int val){
    while(idx <= n){
        bit[idx] = min(bit[idx] , val);
        idx += idx & -idx;
    }
}
int query(int idx){
    int res = inf;
    while(idx){
        res = min(res , bit[idx]);
        idx -= idx & -idx;
    }
    return res;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    build();
    scanf("%d" , &q);
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d %d" , l + i , r + i);
        v[l[i]].emplace_back(i);
    }
    for(int i = 1 ; i <= n ; ++i){
        bit[i] = inf;
    }
    for(int i = n ; i >= 1 ; --i){
        for(int j = 0 ; nxt1[i][j] ; ++j){
            update(nxt1[i][j] , arr[nxt1[i][j]] - arr[i]);
        }
        for(int j = 0 ; nxt2[i][j] ; ++j){
            update(nxt2[i][j] , arr[i] - arr[nxt2[i][j]]);
        }
        for(int idx : v[i]){
            ans[idx] = query(r[idx]);
        }
    }
    for(int i = 1 ; i <= q ; ++i){
        printf("%d\n" , ans[i]);
    }
}