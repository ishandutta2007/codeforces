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
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 2e5 + 5;
LL mx[MAXN<<2],tag[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void pushup(int x){
    mx[x] = std::max(mx[lc],mx[rc]); 
}

inline void cover(int x,LL d){
    mx[x] += d;tag[x] += d;
}

inline void pushdown(int x){
    if(tag[x]){
        cover(lc,tag[x]);cover(rc,tag[x]);
        tag[x]  =0;
    }
}

inline void modify(int x,int l,int r,int L,int R,LL d){
    if(l == L && r == R){
        cover(x,d);return;
    }
    int mid = (l + r) >> 1;pushdown(x);
    if(R <= mid) modify(lc,l,mid,L,R,d);
    else if(L > mid) modify(rc,mid+1,r,L,R,d);
    else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
    pushup(x);
}

inline LL query(int x,int l,int r,int L,int R){
    if(l == L && r == R) return mx[x];
    pushdown(x);int mid = (l + r) >> 1;
    if(R <= mid) return query(lc,l,mid,L,R);
    if(L > mid) return query(rc,mid+1,r,L,R);
    return std::max(query(lc,l,mid,L,mid),query(rc,mid+1,r,mid+1,R));
}
P a[MAXN],b[MAXN];
inline void build(int x,int l,int r){
    if(l == r) {mx[x] = -b[l].se;return;}
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
    pushup(x);
}

int n,m,p;
std::pair<P,int> c[MAXN];
std::vector<int> G;

inline bool cmp(int a,int b){
    return a <= b;
}

signed main(){
    scanf("%lld%lld%lld",&n,&m,&p);
    FOR(i,1,n) scanf("%lld%lld",&a[i].fi,&a[i].se);
    FOR(i,1,m) scanf("%lld%lld",&b[i].fi,&b[i].se),G.pb(b[i].fi);
    FOR(i,1,p) scanf("%lld%lld%lld",&c[i].fi.fi,&c[i].fi.se,&c[i].se);
    std::sort(a+1,a+n+1);std::sort(b+1,b+m+1);std::sort(c+1,c+p+1);build(1,1,m);
    std::sort(all(G));
    int ps = 1;LL ans = -1e18;
    FOR(i,1,n){
        while(ps <= m && c[ps].fi.fi < a[i].fi){
            int p = std::lower_bound(all(G),c[ps].fi.se,cmp)-G.begin();
            if(p < m) modify(1,1,m,p+1,m,c[ps].se);
            ps++;
        }
        ans = std::max(ans,mx[1]-a[i].se);
    }
    printf("%lld\n",ans);
    return 0;
}