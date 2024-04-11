#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
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

const int MAXN = 3e5 + 5;
int a[MAXN],p[MAXN];
int f[MAXN<<2],g[MAXN<<2],min[MAXN<<2],tag[MAXN<<2];

#define lc (x<<1)
#define rc (x<<1|1)

inline void pushup(int x){
    min[x] = std::min(min[lc],min[rc]);
    f[x] = f[lc]*(min[x] == min[lc]) + f[rc]*(min[x] == min[rc]);
    g[x] = g[lc]*(min[x] == min[lc]) + g[rc]*(min[x] == min[rc]) + f[lc]*(min[x] == min[lc]-1) + f[rc]*(min[x] == min[rc]-1);
}

inline void add(int x,int v){
    min[x] += v;tag[x] += v;
}

inline void pushdown(int x){
    if(tag[x]){
        add(lc,tag[x]);add(rc,tag[x]);
        tag[x] = 0;
    }
}

inline void build(int x,int l,int r){
    if(l == r){
        f[x] = 1;return;
    }
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
}

inline void modify(int x,int l,int r,int L,int R,int d){
    if(l == L && r == R){
        add(x,d);return;
    }
    pushdown(x);
    int mid = (l + r) >> 1;
    if(R <= mid) modify(lc,l,mid,L,R,d);
    else if(L > mid) modify(rc,mid+1,r,L,R,d);
    else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
    pushup(x);
}

inline int query(int x,int l,int r,int L,int R){
    if(l == L && r == R) return f[x]*(min[x] <= 2)+g[x]*(min[x] <= 1);
    pushdown(x);
    int mid = (l + r) >> 1;
    if(R <= mid) return query(lc,l,mid,L,R);
    if(L > mid) return query(rc,mid+1,r,L,R);
    return query(lc,l,mid,L,mid)+query(rc,mid+1,r,mid+1,R);
}

int n;

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),p[a[i]] = i;
    build(1,1,n);
    LL ans = 0;
    FOR(i,1,n){
        int pre = a[p[i]-1],suf = a[p[i]+1];
        modify(1,1,n,1,i,1);
        if(pre && pre < i) modify(1,1,n,1,pre,-1);
        if(suf && suf < i) modify(1,1,n,1,suf,-1);
        ans += query(1,1,n,1,i);
    }
    printf("%lld\n",ans-n);
    return 0;
}