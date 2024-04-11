/*
 * Author: RainAir
 * Time: 2019-08-24 08:57:53
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
const int MAXN = 3e5 + 5;
#define lc ((x)<<1)
#define rc ((x)<<1|1)
int pre[MAXN<<2],suf[MAXN<<2],ans[MAXN<<2];
int val[MAXN];

inline int sgn(int x){
    return !x ? 0 : (x > 0 ? 1 : -1);
}

inline void pushup(int x,int l,int r){
    int mid = (l + r) >> 1;
    pre[x] = pre[lc];suf[x] = suf[rc];
    ans[x] = std::max(ans[lc],ans[rc]);
    if(val[mid] && val[mid+1] && sgn(val[mid]) >= sgn(val[mid+1])){
        ans[x] = std::max(ans[x],suf[lc]+pre[rc]);
        if(pre[lc] == mid-l+1) pre[x] = pre[lc]+pre[rc];
        if(suf[rc] == r-mid) suf[x] = suf[rc]+suf[lc];
    }
}

inline void build(int x,int l,int r){
    if(l == r){
        pre[x] = suf[x] = ans[x] = val[l] != 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
    pushup(x,l,r);
}

inline void update(int x,int l,int r,int p){
    if(l == r){
        pre[x] = suf[x] = ans[x] = val[l] != 0;
        return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid) update(lc,l,mid,p);
    else update(rc,mid+1,r,p);
    pushup(x,l,r);
}

int n,m,a[MAXN];

signed main(){
    scanf("%lld",&n);
    FOR(i,1,n) scanf("%lld",a+i);n--;
    if(!n){
        scanf("%lld",&m);
        while(m--) scanf("%*d%*d%*d"),puts("1");return 0;
    }
    FOR(i,1,n) val[i] = a[i+1]-a[i];
    build(1,1,n);scanf("%lld",&m);
    FOR(i,1,m){
        int l,r,d;scanf("%lld%lld%lld",&l,&r,&d);
        if(l != 1) val[l-1] += d,update(1,1,n,l-1);
        if(r != n+1) val[r] -= d,update(1,1,n,r);
        printf("%lld\n",ans[1]+1);
    }
    return 0;
}