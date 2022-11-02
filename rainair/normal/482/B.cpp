/*
 * Author: RainAir
 * Time: 2019-08-23 11:22:42
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

const int MAXN = 1e5 + 5;

struct SegmentTree{
    #define lc ((x)<<1)
    #define rc ((x)<<1|1)
    int sm[MAXN<<2],tag[MAXN<<2];

    inline void cover(int x,int l,int r,int d){
        sm[x] |= d;tag[x] |= d;
    }
    
    inline void pushdown(int x,int l,int r){
        if(tag[x]){
            int mid = (l + r) >> 1;
            cover(lc,l,mid,tag[x]);cover(rc,mid+1,r,tag[x]);
            tag[x] = 0;
        }
    }

    inline void modify(int x,int l,int r,int L,int R,int d){
        if(l == L && r == R){
            cover(x,l,r,d);return;
        }
        int mid = (l + r) >> 1;pushdown(x,l,r);
        if(R <= mid) modify(lc,l,mid,L,R,d);
        else if(L > mid) modify(rc,mid+1,r,L,R,d);
        else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
    }

    inline int calc(int x,int l,int r,int p){
        if(l == r) return sm[x];
        int mid = (l + r) >> 1;pushdown(x,l,r);
        return p <= mid ? calc(lc,l,mid,p) : calc(rc,mid+1,r,p);
    }
}seg;

int n,m;
int ans[MAXN];
int ad[MAXN<<2];

inline void build(int x,int l,int r){
    if(l == r){
        ad[x] = ans[l];return;
    }
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
    ad[x] = ad[lc]&ad[rc];
}

inline int query(int x,int l,int r,int L,int R){
    if(l == L && r == R) return ad[x];
    int mid = (l + r) >> 1;
    if(R <= mid) return query(lc,l,mid,L,R);
    else if(L > mid) return query(rc,mid+1,r,L,R);
    else return query(lc,l,mid,L,mid)&query(rc,mid+1,r,mid+1,R);
}

int ll[MAXN],rr[MAXN],xx[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int l,r,x;scanf("%d%d%d",&l,&r,&x);
        ll[i] = l;rr[i] = r;xx[i] = x;
        seg.modify(1,1,n,l,r,x);
    }
    FOR(i,1,n){
        int t = seg.calc(1,1,n,i);
        ans[i] = t;
    }
    build(1,1,n);
    FOR(i,1,m){
        if(query(1,1,n,ll[i],rr[i]) != xx[i]){
            puts("NO");return 0;
        }
    }
    puts("YES");
    FOR(i,1,n) printf("%d ",ans[i]);
    return 0;
}