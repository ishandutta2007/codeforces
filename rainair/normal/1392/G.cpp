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

const int MAXN = 1e6 + 5;
int n,m,k;
char str[21];
int x[MAXN],y[MAXN];
int s[MAXN],t[MAXN];
int p[21];
int f[(1<<20)+3],g[(1<<20)+3];
// f  g 

inline void presum(){
    FOR(i,0,k-1){
        FOR(S,0,(1<<k)-1){
            if((S>>i)&1) continue;
            f[S] = std::min(f[S^(1<<i)],f[S]);
            g[S] = std::max(g[S^(1<<i)],g[S]);
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    scanf("%s",str);FOR(i,0,k-1) if(str[i] == '1') s[0] |= (1<<i);
    scanf("%s",str);FOR(i,0,k-1) if(str[i] == '1') t[0] |= (1<<i);
    FOR(i,1,n) scanf("%d%d",x+i,y+i);FOR(i,1,k) p[i] = i;
    FOR(i,1,n){
        int p1=-1,p2=-1;
        FOR(j,1,k){
            if(p[j] == x[i]) p1 = j;
            if(p[j] == y[i]) p2 = j;
        }
        std::swap(p[p1],p[p2]);
//        FOR(i,1,k) printf("%d" ,p[i]);puts("");
        FOR(j,0,k-1) if((s[0]>>(p[j+1]-1))&1) s[i] |= 1<<j;
        FOR(j,0,k-1) if((t[0]>>(p[j+1]-1))&1) t[i] |= 1<<j;
//        FOR(j,0,k-1) printf("%d",(s[i]>>j)&1);puts("");
    }
    FOR(i,0,(1<<k)-1) f[i] = 1e9,g[i] = -1e9;
    FOR(i,0,n) f[s[i]] = std::min(f[s[i]],i),g[t[i]] = std::max(g[t[i]],i);
    presum();
    int ans = -1e9,ansl = -1,ansr = -1;
    FOR(S,0,(1<<k)-1){
        if(g[S]-f[S] >= m && __builtin_popcount(S) > ans){
            ans = __builtin_popcount(S);
            ansl = f[S]+1;ansr = g[S];
        }
    }
    ans = 2*ans+k-__builtin_popcount(s[0])-__builtin_popcount(t[0]);
    printf("%d\n%d %d\n",ans,ansl,ansr);
    return 0;
}