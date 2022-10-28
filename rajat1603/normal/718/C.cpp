#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
const int mod = 1e9 + 7;
int add(int a , int b){
    int res = a + b;
    if(res >= mod){
        return res - mod;
    }
    return res;
}
int mult(int a , int b){
    long long res = a;
    res *= b;
    if(res >= mod){
        return res % mod;
    }
    return res;
}
const int SZ = 2;
struct matrix{
    int arr[SZ][SZ];
    void reset(){
        memset(arr , 0 , sizeof(arr));
    }
    void makeiden(){
        reset();
        for(int i = 0 ; i < SZ ; ++i){
            arr[i][i] = 1;
        }
    }
    matrix operator + (const matrix &o) const {
        matrix res;
        for(int i = 0 ; i < SZ ; ++i){
            for(int j = 0 ; j < SZ ; ++j){
                res.arr[i][j] = add(arr[i][j] , o.arr[i][j]);
            }
        }
        return res;
    }
    matrix operator * (const matrix &o) const {
        matrix res;
        for(int i = 0 ; i < SZ ; ++i){
            for(int j = 0 ; j < SZ ; ++j){
                res.arr[i][j] = 0;
                for(int k = 0 ; k < SZ ; ++k){
                    res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
                }
            }
        }
        return res;
    }
};
matrix power(matrix a , int b){
    matrix res;
    res.makeiden();
    while(b){
        if(b & 1){
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}
int n , q;
int arr[N];
int type , l , r;
matrix segtree[SN];
matrix lazy[SN];
bool upd[SN];
matrix fib;
matrix tmp;
int x;
void build(int l , int r , int node){
    upd[node] = 0;
    lazy[node].makeiden();
    if(l == r){
        segtree[node] = power(fib , arr[l]);
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        segtree[node] = segtree[node + node] + segtree[node + node + 1];
    }
}
void push(int l , int r , int node){
    if(upd[node]){
        segtree[node] = segtree[node] * lazy[node];
        if(l != r){
            upd[node + node] = 1;
            upd[node + node + 1] = 1;
            lazy[node + node] = lazy[node + node] * lazy[node];
            lazy[node + node + 1] = lazy[node + node + 1] * lazy[node];
        }
        upd[node] = 0;
        lazy[node].makeiden();
    }
}
void update(int l , int r , int node , int ql , int qr){
    push(l , r , node);
    if(l > qr || r < ql){
        return;
    }
    if(l >= ql && r <= qr){
        lazy[node] = lazy[node] * tmp;
        upd[node] = 1;
        push(l , r , node);
        return;
    }
    int mid = l + r >> 1;
    update(l , mid , node + node , ql , qr);
    update(mid + 1 , r , node + node + 1 , ql , qr);
    segtree[node] = segtree[node + node] + segtree[node + node + 1];
}
int ans;
void query(int l , int r , int node , int ql , int qr){
    push(l , r , node);
    if(l > qr || r < ql){
        return;
    }
    if(l >= ql && r <= qr){
        ans = add(ans , segtree[node].arr[0][1]);
        return;
    }
    int mid = l + r >> 1;
    query(l , mid , node + node , ql , qr);
    query(mid + 1 , r , node + node + 1 , ql , qr);
}
int main(){
    scanf("%d %d" , &n , &q);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    fib.arr[0][0] = 1;
    fib.arr[0][1] = 1;
    fib.arr[1][0] = 1;
    fib.arr[1][1] = 0;
    build(1 , n , 1);
    while(q--){
        scanf("%d %d %d" , &type , &l , &r);
        if(type == 1){
            scanf("%d" , &x);
            tmp = power(fib , x);
            update(1 , n , 1 , l , r);
        }
        else{
            ans = 0;
            query(1 , n , 1 , l , r);
            printf("%d\n" , ans);
        }
    }
}