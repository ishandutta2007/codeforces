/*
 * Author: RainAir
 * Time: 2019-08-23 10:36:51
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
const int MAXN = 1e5 + 5;
#define lc ((x<<1))
#define rc ((x<<1)|1)
int sm[MAXN<<2][5],sz[MAXN<<2];

inline void pushup(int x){
    sz[x] = sz[lc] + sz[rc];int ls = sz[lc];
    FOR(i,0,4){
        sm[x][i] = sm[lc][i]+sm[rc][(i-ls%5+5)%5]; // x == r-ls
    }
}

inline void update(int x,int l,int r,int pos,int d1,int d2){
    if(l == r){
        sz[x] += d1;sm[x][0] += d2;
        return;
    }
    int mid = (l + r) >> 1;
//    printf("%d %d %d\n",d1,d2,x);
    if(pos <= mid) update(lc,l,mid,pos,d1,d2);
    else update(rc,mid+1,r,pos,d1,d2);
    pushup(x);
}
 
int n;
int opt[MAXN],a[MAXN],b[MAXN],cnt;
char str[233];

signed main(){
    scanf("%lld",&n);
    FOR(i,1,n){
        scanf("%s",str);
        opt[i] = str[0] == 'a' ? 1 : (str[0] == 'd' ? 2 : 3);
        if(opt[i] <= 2) scanf("%lld",a+i),b[++cnt] = a[i];
    }
    std::sort(b+1,b+cnt+1);cnt = std::unique(b+1,b+cnt+1)-b-1;
    /*FOR(i,1,n) if(opt[i] <= 2){
        a[i] = std::lower_bound(b+1,b+cnt+1,a[i])-b;
    }*/
    FOR(i,1,n){
        if(opt[i] == 1) update(1,1,n,std::lower_bound(b+1,b+cnt+1,a[i])-b,1,a[i]);
        if(opt[i] == 2) update(1,1,n,std::lower_bound(b+1,b+cnt+1,a[i])-b,-1,-a[i]);
        if(opt[i] == 3){
            printf("%lld\n",sm[1][2]);
        }
    }
    return 0;
}