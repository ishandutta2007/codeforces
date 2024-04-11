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

const int MAXN = 2e5 + 5;

int a[MAXN],n;
bool p[MAXN];
int prime[MAXN],id[MAXN],cnt;
std::vector<int> G[MAXN];

inline void prework(){
    FOR(i,2,MAXN-1){
        if(!p[i]) prime[++cnt] = i,id[i] = cnt;
        for(int j = 1;j <= cnt && i*prime[j] < MAXN;++j){
            p[i*prime[j]] = 1;
            if(!(i%prime[j])) break;
        }
    }
}

inline void fj(int x){
    int q = std::sqrt(1.0*x);
    FOR(i,1,cnt){
        if(prime[i] > q) break;
        if(prime[i] > x) break;
        if(x%prime[i]) continue;
        int t = 0;
        while(!(x%prime[i])) x /= prime[i],++t;
        G[i].pb(t);
    }
    if(x != -1) G[id[x]].pb(1);
}

int main(){
    prework();
    scanf("%d",&n);
    FOR(i,1,n){
        int x;scanf("%d",&x);fj(x);
    }
    LL ans = 1;
    FOR(i,1,cnt){
        if((int)G[i].size() <= n-2) continue;
        int mn = 1e9,cmn = 1e9;
        if((int)G[i].size() == n-1) mn = 0;
        for(auto x:G[i]){
            if(mn > x) cmn = mn,mn = x;
            else if(cmn > x) cmn = x;
        }
        FOR(j,1,cmn) ans *= prime[i];
    }
    printf("%lld\n",ans);
    return 0;
}