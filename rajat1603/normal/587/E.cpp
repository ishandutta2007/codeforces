#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int SN = 1 << 19;
const int LN = 31;
struct gauss{
    int basis[LN];
    void reset(){
        memset(basis , 0 , sizeof(basis));
    }
    void insert(int val){
        for(int i = LN - 1 ; i >= 0 && val > 0 ; --i){
            if((val >> i) & 1){
                if(basis[i]){
                    val ^= basis[i];
                }
                else{
                    basis[i] = val;
                    val = 0;
                }
            }
        }
    }
};
void combine(gauss &res , const gauss &lft , const gauss &rgt){
    res = lft;
    for(int i = 0 ; i < LN ; ++i){
        if(rgt.basis[i]){
            res.insert(rgt.basis[i]);
        }
    }
}
int n , q;
int arr[N];
gauss segtree[SN];
gauss res;
void build(int l , int r , int node){
    if(l == r){
        segtree[node].reset();
        segtree[node].insert(arr[l]);
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        combine(segtree[node] , segtree[node + node] , segtree[node + node + 1]);
    }
}
void update(int l , int r , int node , int idx){
    if(l == r){
        segtree[node].reset();
        segtree[node].insert(arr[l]);
    }
    else{
        int mid = l + r >> 1;
        if(idx <= mid){
            update(l , mid , node + node , idx);
        }
        else{
            update(mid + 1 , r , node + node + 1 , idx);
        }
        combine(segtree[node] , segtree[node + node] , segtree[node + node + 1]);
    }
}
void query(int l , int r , int node , int ql , int qr){
    if(l > qr || r < ql){
        return;
    }
    if(l >= ql && r <= qr){
        combine(res , res , segtree[node]);
        return;
    }
    int mid = l + r >> 1;
    query(l , mid , node + node , ql , qr);
    query(mid + 1 , r , node + node + 1 , ql , qr);
}
int bit[N];
void update(int idx , int val){
    while(idx <= n){
        bit[idx] ^= val;
        idx += idx & -idx;
    }
}
int query(int idx){
    int res = 0;
    while(idx){
        res ^= bit[idx];
        idx -= idx & -idx;
    }
    return res;
}
int type , l , r , k;
int main(){
    scanf("%d %d" , &n , &q);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = n ; i >= 1 ; --i){
        arr[i] ^= arr[i - 1];
        update(i , arr[i]);
    }
    build(1 , n , 1);
    while(q--){
        scanf("%d %d %d" , &type , &l , &r);
        if(type == 1){
            scanf("%d" , &k);
            arr[l] ^= k;
            arr[r + 1] ^= k;
            update(l , k);
            update(r + 1 , k);
            update(1 , n , 1 , l);
            update(1 , n , 1 , r + 1);
        }
        else{
            res.reset();
            query(1 , n , 1 , l + 1 , r);
            res.insert(query(l));
            int ans = 0;
            for(int i = 0 ; i < LN ; ++i){
                ans += !!res.basis[i];
            }
            printf("%d\n" , 1 << ans);
        }
    }
}