#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int M = 1e3 + 3;
const int SN = 1 << 18;
const int mxx = M >> 5;
int n , m;
int arr[N];
int tin[N];
int tout[N];
int timer = 0;
int lazy[SN];
bitset < M > segtree[SN];
int tmparr[N];
bool isprime[M];
int primes[M];
int rev[N];
int cnt = 0;
int a , b;
vector < int > v[N];
int type;
bitset < M > msk;
inline void gen(){
    for(int i = 2 ; i <= m ; ++i){
        bool ok = 1;
        for(int j = 2 ; j * j <= i ; ++j){
            if(i % j == 0){
                ok = 0;
            }
        }
        if(ok){
            primes[++cnt] = i;
            isprime[i] = 1;
            msk.set(i);
        }
    }
}
void dfs(int node , int parent){
    tin[node] = ++timer;
    rev[timer] = node;
    tmparr[timer] = arr[node];
    for(int next : v[node]){
        if(next != parent){
            dfs(next , node);
        }
    }
    tout[node] = timer;
}
void build(int l , int r , int node){
    if(l == r){
        segtree[node].set(tmparr[l]); 
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        segtree[node] = segtree[node + node] | segtree[node + node + 1];
    }
    lazy[node] = 0;
}
bitset < M > inf;
void shift(bitset < M > &b , int val){
    b = ((b << val) & inf) | (b >> (m - val));
}
void push(int l , int r , int node){
    if(lazy[node]){
        lazy[node] %= m;
        shift(segtree[node] , lazy[node]);
        if(l != r){
            (lazy[node + node] += lazy[node]) %= m;
            (lazy[node + node + 1] += lazy[node]) %= m;
        }
        lazy[node] = 0;
    }
}
void update(int l , int r , int node , int ql , int qr , int val){
    if(l > qr || r < ql){
        push(l , r , node);
        return;
    }
    if(l >= ql && r <= qr){
        lazy[node] += val;
        push(l , r , node);
        return;
    }
    push(l , r , node);
    int mid = l + r >> 1;
    update(l , mid , node + node , ql , qr , val);
    update(mid + 1 , r , node + node + 1 , ql , qr , val);
    segtree[node] = segtree[node + node] | segtree[node + node + 1];
}
bitset < M > ret;
void query(int l , int r , int node , int ql , int qr){
    push(l , r , node);
    if(l > qr || r < ql){
        return;
    }
    if(l >= ql && r <= qr){
        ret |= segtree[node];
        return;
    }
    int mid = l + r >> 1;
    query(l , mid , node + node , ql , qr);
    query(mid + 1 , r , node + node + 1 , ql , qr);
}
int main(){
    scanf("%d %d" , &n , &m);
    gen();
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        arr[i] %= m;
    }
    for(int i = 0 ; i < m ; ++i){
        inf.set(i);
    }
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    dfs(1 , 0);
    build(1 , n , 1);
    int q;
    scanf("%d" , &q);
    while(q--){
        scanf("%d" , &type);
        if(type == 1){
            scanf("%d %d" , &a , &b);
            int l = tin[a];
            int r = tout[a];
            b %= m;
            update(1 , n , 1 , l , r , b);
        }
        else{
            scanf("%d" , &a);
            int l = tin[a];
            int r = tout[a];
            ret.reset();
            query(1 , n , 1 , l , r);
            int ans = (ret & msk).count();
            printf("%d\n" , ans);
        }
    }
}