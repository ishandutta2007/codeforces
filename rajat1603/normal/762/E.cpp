#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int M = 3e5 + 5;
const int F = 1e4 + 4;
const int LN = 20;
const int SZ = F + LN * M;
int n , m , k;
int x[N] , r[N] , f[N];
int newx[N];
int newxpre[N];
int newxsuf[N];
int tmp[M];
int cur;
int root[F];
int segtree[SZ][3];
vector < int > add[M];
vector < int > sub[M];
vector < int > v[M];
long long ans;
void update(int l , int r , int node , int idx , int val){
    segtree[node][0] += val;
    if(l < r){
        int mid = l + r >> 1;
        if(idx <= mid){
            int &lft = segtree[node][1];
            if(!lft){
                lft = ++cur;
            }
            update(l , mid , lft , idx , val);
        }
        else{
            int &rgt = segtree[node][2];
            if(!rgt){
                rgt = ++cur;
            }
            update(mid + 1 , r , rgt , idx , val);
        }
    }
}
int query(int l , int r , int node , int ql , int qr){
    if(l > qr || r < ql || !node){
        return 0;
    }
    if(l >= ql && r <= qr){
        return segtree[node][0];
    }
    int mid = l + r >> 1;
    return query(l , mid , segtree[node][1] , ql , qr) + query(mid + 1 , r , segtree[node][2] , ql , qr);
}
int main(){
    scanf("%d %d" , &n , &k);
    m = 0;
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d %d" , x + i , r + i , f + i);
        tmp[m++] = x[i];
        tmp[m++] = x[i] - r[i];
        tmp[m++] = x[i] + r[i];
    }
    sort(tmp , tmp + m);
    m = unique(tmp , tmp + m) - tmp;
    for(int i = 1 ; i <= n ; ++i){
        newx[i] = lower_bound(tmp , tmp + m , x[i]) - tmp + 1;
        newxpre[i] = lower_bound(tmp , tmp + m , x[i] - r[i]) - tmp + 1; 
        newxsuf[i] = lower_bound(tmp , tmp + m , x[i] + r[i]) - tmp + 1;
    }
    cur = 0;
    for(int i = 1 ; i < F ; ++i){
        root[i] = ++cur;
    }
    for(int i = 1 ; i <= n ; ++i){
        add[newx[i]].emplace_back(f[i]);
        sub[newxsuf[i]].emplace_back(i);
        v[newx[i]].emplace_back(i);
    }
    for(int i = 1 ; i <= m ; ++i){
        for(int idx : v[i]){
            for(int j = max(1 , f[idx] - k) ; j <= min(F - 1 , f[idx] + k) ; ++j){
                ans += query(1 , m , root[j] , newxpre[idx] , i);
            }
        }
        for(int shit : add[i]){
            update(1 , m , root[shit] , i , 1);
        }
        for(int idx : sub[i]){
            update(1 , m , root[f[idx]] , newx[idx] , -1);
        }
    }
    printf("%lld\n" , ans);
}