/*
 * Author: RainAir
 * Time: 2020-03-05 10:50:00
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
int p[MAXN],a[MAXN];
int ps[MAXN]; // where i
int n;

struct SegmentTree{
    #define lc ((x)<<1)
    #define rc ((x)<<1|1)
    struct Node{
        LL val;
        Node(LL val=0) : val(val)  {}

        inline Node operator + (const Node &t) const {
            return Node(std::min(val,t.val));
        }
    }sm[MAXN<<2];
    LL tag[MAXN<<2];

    inline void pushup(int x){
        sm[x] = sm[lc]+sm[rc];
    }

    inline void cover(int x,int l,int r,LL d){
        sm[x].val += d;
        tag[x] += d;
    }

    inline void pushdown(int x,int l,int r){
        if(tag[x]){
            int mid = (l + r) >> 1;
            cover(lc,l,mid,tag[x]);cover(rc,mid+1,r,tag[x]);
            tag[x] = 0;
        }
    }

    inline void modify(int x,int l,int r,int L,int R,LL d){
        if(L > R) return;
        if(l == L && r == R) {cover(x,l,r,d);return;}
        int mid = (l + r) >> 1;
        pushdown(x,l,r);
        if(R <= mid) modify(lc,l,mid,L,R,d);
        else if(L > mid) modify(rc,mid+1,r,L,R,d);
        else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
        pushup(x);
    }

    inline Node query(int x,int l,int r,int L,int R){
        if(l == L && r == R) return sm[x];
        int mid = (l + r) >> 1;pushdown(x,l,r);
        if(R <= mid) return query(lc,l,mid,L,R);
        if(L > mid) return query(rc,mid+1,r,L,R);
        return query(lc,l,mid,L,mid)+query(rc,mid+1,r,mid+1,R);
    }
    #undef lc
    #undef rc
}tree;

signed main(){
    scanf("%lld",&n);
    FOR(i,1,n) scanf("%lld",p+i),ps[p[i]] = i;
    FOR(i,1,n) scanf("%lld",a+i);
    int pre = 0;
    FOR(i,1,n-1) pre += a[i],tree.modify(1,1,n-1,i,i,pre);
    int ans = tree.sm[1].val;
    FOR(val,1,n){ // add val to pre
        tree.modify(1,1,n-1,ps[val],n-1,-a[ps[val]]);
        tree.modify(1,1,n-1,1,ps[val]-1,a[ps[val]]);
        ans = std::min(ans,tree.sm[1].val);
    }
    printf("%lld\n",ans);
    return 0;
}