#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 1;
const int SN = 1 << 18;
int arr[N];
long long segtree[SN];
int segtree2[SN];
int n , q;
void build(int l , int r , int node){
    if(l == r){
        segtree[node] = arr[l];
        segtree2[node] = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    int lc = node + node;
    int rc = lc | 1;
    build(l , mid , lc);
    build(mid + 1 , r , rc);
    segtree[node] = segtree[lc] + segtree[rc];
    segtree2[node] = max(segtree2[lc] , segtree2[rc]);
}
void update(int l , int r , int node , int ql , int qr , int val){
    if(l > qr || r < ql || segtree2[node] < val){
        return;
    }
    if(l == r){
        segtree[node] = segtree[node] % val;
        segtree2[node] = segtree[node];
        return;
    }
    int mid = (l + r) >> 1;
    int lc = node + node;
    int rc = lc | 1;
    update(l , mid , lc , ql , qr , val);
    update(mid + 1 , r , rc , ql , qr , val);
    segtree[node] = segtree[lc] + segtree[rc];
    segtree2[node] = max(segtree2[lc] , segtree2[rc]);
}
void rebuild(int l , int r , int node , int idx , int val){
    if(l == r){
        segtree[node] = val;
        segtree2[node] = val;
        return;
    }
    int mid = (l + r) >> 1;
    int lc = node + node;
    int rc = lc | 1;
    if(idx <= mid){
        rebuild(l , mid , lc , idx , val);
    }
    else{
        rebuild(mid + 1 , r , rc , idx , val);
    }
    segtree[node] = segtree[lc] + segtree[rc];
    segtree2[node] = max(segtree2[lc] , segtree2[rc]);
}
long long query(int l , int r , int node , int ql , int qr){
    if(l > qr || r < ql){
        return 0LL;
    }
    if(l >= ql && r <= qr){
        return segtree[node];
    }
    int mid = (l + r) >> 1;
    int lc = node + node;
    int rc = lc | 1;
    return query(l , mid , lc , ql , qr) + query(mid + 1 , r , rc , ql, qr);
}
int main(){
    cin >> n >> q;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    build(1 , n , 1);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l , r;
            cin >> l >> r;
            cout << query(1 , n , 1 , l , r) << "\n";
        }
        else if(type == 2){
            int l , r , mod;
            cin >> l >> r >> mod;
            update(1 , n , 1 , l , r , mod);
        }
        else{
            int idx , val;
            cin >> idx >> val;
            rebuild(1 , n , 1 , idx , val);
        }
    }
}