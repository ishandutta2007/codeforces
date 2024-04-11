/*
 * Author: RainAir
 * Time: 2019-08-24 09:45:40
 */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

#define int LL
const int ha = 1e9 + 7;
const int MAXN = 1e5 + 5;

struct Matrix{
    int a[2][2];
    Matrix(){CLR(a,0);}

    void clear(){
        a[0][1] = a[1][0] = 0;
        a[0][0] = a[1][1] = 1;
    }

    friend Matrix operator + (const Matrix &a,const Matrix &b){
        Matrix res;
        FOR(i,0,1) FOR(j,0,1) res.a[i][j] = (a.a[i][j]+b.a[i][j]) % ha;
        return res;
    }
    
    friend Matrix operator * (const Matrix &a,const Matrix &b){
        Matrix res;
        FOR(i,0,1){
            FOR(j,0,1){
                FOR(k,0,1){
                    (res.a[i][j] += a.a[i][k]*b.a[k][j]%ha) %= ha;
                }
            }
        }
        return res;
    }

    inline void debug(){
        puts("--DEBUG--");
        FOR(i,0,1) FOR(j,0,1) printf("%d%c",a[i][j],j==1?'\n':' ');
    }
};

inline Matrix qpow(Matrix a,int n){
    n = std::max(n,0ll);
    Matrix res;res.a[0][0] = res.a[1][1] = 1;
    while(n){
        if(n & 1) res = res*a;
        a = a*a;
        n >>= 1;
    }
    return res;
}

#define lc ((x)<<1)
#define rc ((x)<<1|1)
Matrix sm[MAXN<<2],tag[MAXN<<2],base;
bool tgs[MAXN<<2];int a[MAXN];

inline void pushup(int x){
    sm[x] = sm[lc]+sm[rc];
}

inline void cover(int x,Matrix d){
    sm[x] = sm[x]*d;
    tag[x] = tag[x]*d;tgs[x] = true;
}

inline void build(int x,int l,int r){
    tag[x].clear();
    if(l == r){
        sm[x] = qpow(base,a[l]-1);
        return;
    }
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
    pushup(x);
}

inline void pushdown(int x){
    if(tgs[x]){
        cover(lc,tag[x]);
        cover(rc,tag[x]);
        tag[x].clear();
        tgs[x] = 0;
    }
}

inline void modify(int x,int l,int r,int L,int R,Matrix d){
    if(l == L && r == R){
        cover(x,d);
  //      sm[x].debug();
        return;
    }
    int mid = (l + r) >> 1;pushdown(x);
    if(R <= mid) modify(lc,l,mid,L,R,d);
    else if(L > mid) modify(rc,mid+1,r,L,R,d);
    else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
    pushup(x);
}

inline int query(int x,int l,int r,int L,int R){
//    sm[x].debug();
    if(l == L && r == R) return sm[x].a[0][0];
    int mid = (l + r) >> 1;pushdown(x);
    if(R <= mid) return query(lc,l,mid,L,R);
    if(L > mid) return query(rc,mid+1,r,L,R);
    return (query(lc,l,mid,L,mid)+query(rc,mid+1,r,mid+1,R)) % ha;
}

int n,m;

signed main(){
    scanf("%lld%lld",&n,&m);
    FOR(i,1,n) scanf("%lld",a+i);
    base.a[0][0] = base.a[0][1] = base.a[1][0] = 1;
    build(1,1,n);
    FOR(i,1,m){
        int opt,l,r;scanf("%lld%lld%lld",&opt,&l,&r);
        if(opt == 1){
            int d;scanf("%lld",&d);
            modify(1,1,n,l,r,qpow(base,d));
        }
        else printf("%lld\n",query(1,1,n,l,r));
    }
    return 0;
}