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
#define db double
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

const int MAXN = 3e5 + 5;

int mn[MAXN<<2],tag[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void cover(int x,int d){
    mn[x] += d;tag[x] += d;
}

inline void pushdown(int x){
    if(tag[x]){
        cover(lc,tag[x]);cover(rc,tag[x]);
        tag[x] = 0;
    }
}

inline void modify(int x,int l,int r,int L,int R,int d){
    if(l == L && r == R){cover(x,d);return;}
    int mid = (l + r) >> 1;pushdown(x);
    if(R <= mid) modify(lc,l,mid,L,R,d);
    else if(L > mid) modify(rc,mid+1,r,L,R,d);
    else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
    mn[x] = std::min(mn[lc],mn[rc]);
}

int n;
int ip[MAXN],p[MAXN];

inline bool chk(int x){
    modify(1,1,n,1,ip[x],-1);
    if(mn[1] >= 0) return 1;
    modify(1,1,n,1,ip[x],1);
    return 0;
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",p+i),ip[p[i]] = i;
    int now = n;printf("%d ",now);
    FOR(i,1,n-1){
        int x;scanf("%d",&x);
        modify(1,1,n,1,x,1);
        while(now && chk(now)) now--;
        printf("%d ",now);
    }
    scanf("%*d");puts("");
    return 0;
}