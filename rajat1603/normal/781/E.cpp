#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
const int mod = 1e9 + 7;
struct data{
    int u;
    int l;
    int r;
    int s;
    bool operator < (const data &other) const {
        return u < other.u;
    }
    void read(){
        scanf("%d %d %d %d" , &u , &l , &r , &s);
        s += u;
    }
};
int h , w , n;
data arr[N];
int dp[N];
vector < int > segtree[SN];
int rev[N];
int cur;
int query(int l , int r , int node , int idx){
    while(arr[segtree[node].back()].s < cur){
        segtree[node].pop_back();
    }
    int res = segtree[node].back();
    if(l < r){
        int mid = l + r >> 1;
        if(idx <= mid){
            res = max(res , query(l , mid , node + node , idx));
        }
        else{
            res = max(res , query(mid + 1 , r , node + node + 1 , idx));
        }
    }
    return res;
}
int query(int idx){
    return dp[query(1 , w , 1 , idx)];
}
void update(int l , int r , int node , int ql , int qr , int idx){
    if(l > qr || r < ql){
        return;
    }
    if(l >= ql && r <= qr){
        segtree[node].emplace_back(idx);
        return;
    }
    int mid = l + r >> 1;
    update(l , mid , node + node , ql , qr , idx);
    update(mid + 1 , r , node + node + 1 , ql , qr , idx);
}
void solve(int idx){
    int res = 0;
    cur = arr[idx].u;
    int l = arr[idx].l;
    int r = arr[idx].r;
    if(l > 1){
        res += query(l - 1);
    }
    else{
        res += query(r + 1);
    }
    if(r < w){
        res += query(r + 1);
    }
    else{
        res += query(l - 1);
    }
    if(res >= mod){
        res -= mod;
    }
    dp[idx] = res;
    update(1 , w , 1 , l , r , idx);
}
int main(){
    scanf("%d %d %d" , &h , &w , &n);
    for(int i = 1 ; i <= n ; ++i){
        arr[i].read();
    }
    for(int i = 0 ; i < SN ; ++i){
        segtree[i] = {0};
    }
    sort(arr + 1 , arr + 1 + n);
    arr[0] = {0 , 1 , w , h + 1};
    dp[0] = 1;
    for(int i = 1 ; i <= n ; ++i){
        solve(i);
    }
    int res = 0;
    cur = h + 1;
    for(int i = 1 ; i <= w ; ++i){
        res += query(i);
        if(res >= mod){
            res -= mod;
        }
    }
    printf("%d\n" , res);
}