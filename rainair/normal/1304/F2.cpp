/*
 * Author: RainAir
 * Time: 2020-03-03 11:01:39
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
const int MAXN = 2e4 + 332;

struct SegmentTree{
    #define lc ((x)<<1)
    #define rc ((x)<<1|1)
    struct Node{
        int val;
        Node(int val=0) : val(val)  {}

        inline Node operator + (const Node &t) const {
            return Node(std::max(val,t.val));
        }
    }sm[MAXN<<2];
    int tag[MAXN<<2];

    inline void build(int x,int l,int r){
        sm[x].val = tag[x] = 0;
        if(l == r) return;
        int mid = (l + r) >> 1;
        build(lc,l,mid);build(rc,mid+1,r);
    }

    inline void pushup(int x){
        sm[x] = sm[lc]+sm[rc];
    }

    inline void cover(int x,int l,int r,int d){
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

    inline void modify(int x,int l,int r,int L,int R,int d){
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
        if(L > R) return Node(0);
        if(l == L && r == R) return sm[x];
        int mid = (l + r) >> 1;pushdown(x,l,r);
        if(R <= mid) return query(lc,l,mid,L,R);
        if(L > mid) return query(rc,mid+1,r,L,R);
        return query(lc,l,mid,L,mid)+query(rc,mid+1,r,mid+1,R);
    }
    #undef lc
    #undef rc
}T;

int f[2][MAXN],now;
int n,m,k;
int pre[MAXN],suf[MAXN];
int a[51][MAXN];
int sm[51][MAXN];

int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
    FOR(i,1,n) FOR(j,1,m) sm[i][j] = sm[i][j-1]+a[i][j];
    FOR(i,1,m-k+1) f[now][i] = sm[1][i+k-1]-sm[1][i-1];
    FOR(i,2,n){
        now ^= 1;T.build(1,1,m);
//        FOR(j,0,m+23) pre[j] = suf[j] = 0;
        FOR(j,1,m-k+1) T.modify(1,1,m,j,j,f[now^1][j]+sm[i][j+k-1]-sm[i][j-1]);
//        FOR(j,1,m-k+1) pre[j] = std::max(pre[j-1],f[now^1][j]+sm[i][j+k-1]-sm[i][j-1]);
//        ROF(j,m-k+1,0) suf[j] = std::max(suf[j+1],f[now^1][j]+sm[i][j+k-1]-sm[i][j-1]);
        FOR(j,1,k) T.modify(1,1,m,j,j,-(sm[i][j+k-1]-sm[i][j-1])+sm[i][j+k-1]-sm[i][k]);
//        FOR(j,1,m-k+1) DEBUG(f[now^1][j]);
 //       FOR(j,1,m-k+1) DEBUG(T.query(1,1,m,j,j).val);

        FOR(j,1,m-k+1){
            f[now][j] = T.query(1,1,m,1,m-k+1).val+sm[i][j+k-1]-sm[i][j-1];
            T.modify(1,1,m,std::max(1,j-k+1),j,a[i][j]);
            T.modify(1,1,m,j+1,std::min(m,j+k),-a[i][j+k]);
        }
    }
    int ans = 0;
    FOR(i,1,m) ans = std::max(ans,f[now][i]);
    printf("%d\n",ans);
    return 0;
}
/*
 * f[i][j]   i   i%2   j
 * f[i][j] = f[i-1][k]+cost(j,k)
 * [j,j+l-1] [k,k+l-1]  
 * O(nm^2)
*/