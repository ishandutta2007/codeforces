/*
 * Author: RainAir
 * Time: 2019-08-23 15:03:54
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

const int MAXN = 5e4 + 5;

int mx[MAXN<<2],tag[MAXN<<2];
int f[MAXN],g[MAXN];
#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void clear(){
    CLR(mx,0);CLR(tag,0);CLR(f,0);
}

inline void pushup(int x){
    mx[x] = std::max(mx[lc],mx[rc]);
}

inline void cover(int x,int l,int r,int d){
    mx[x] += d;tag[x] += d;
}

inline void pushdown(int x,int l,int r){
    if(tag[x]){
        int mid = (l + r) >> 1;
        cover(lc,l,mid,tag[x]);
        cover(rc,mid+1,r,tag[x]);
        tag[x] = 0;
    }
}

inline void build(int x,int l,int r){
    if(l == r){
        mx[x] = g[l-1];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
    pushup(x);
}

inline void modify(int x,int l,int r,int L,int R,int d){
    if(L > R) return;
    if(l == L && r == R){
        cover(x,l,r,d);return;
    }
    int mid = (l + r) >> 1;
    pushdown(x,l,r);
    if(R <= mid) modify(lc,l,mid,L,R,d);
    else if(L > mid) modify(rc,mid+1,r,L,R,d);
    else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
    pushup(x);
}

inline int query(int x,int l,int r,int L,int R){
    if(l == L && r == R) return mx[x];
    int mid = (l + r) >> 1;pushdown(x,l,r);
    if(R <= mid) return query(lc,l,mid,L,R);
    if(L > mid) return query(rc,mid+1,r,L,R);
    return std::max(query(lc,l,mid,L,mid),query(rc,mid+1,r,mid+1,R));
    pushup(x);
}

int n,k,a[MAXN],pre[MAXN],lst[MAXN];

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) pre[i] = lst[a[i]],lst[a[i]] = i;
    FOR(i,1,k){
        build(1,1,n);
        FOR(j,1,n){
            modify(1,1,n,pre[j]+1,j,1);
            f[j] = query(1,1,n,1,j);
        }
        FOR(j,1,n) g[j] = f[j];
        clear();
    }
    printf("%d\n",g[n]);
    return 0;
}