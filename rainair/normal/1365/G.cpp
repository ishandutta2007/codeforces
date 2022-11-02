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

const int MAXN = 1e5+5;
int ps[MAXN],cnt;
std::vector<int> G[13];

inline void prework(){
    FOR(S,0,(1<<13)-1){
        if(__builtin_popcount(S) != 6) continue;
        ps[++cnt] = S;
    }
}

inline LL query(std::vector<int> v){
    if(v.size() == 0) return 0;
    printf("? %d ",(int)v.size());
    for(auto x:v) printf("%d ",x);puts("");std::fflush(stdout);
    LL res;scanf("%lld",&res);return res;
}
LL ans[MAXN];
int main(){
    prework();
    int n;scanf("%d",&n);
    FOR(i,1,n) FOR(j,0,12) if((ps[i]>>j)&1) G[j].pb(i);
    FOR(i,0,12) ans[i] = query(G[i]);
    printf("! ");
    FOR(i,1,n){
        LL res = 0;
        FOR(j,0,12){
            if((ps[i]>>j)&1) continue;
            res |= ans[j];
        }
        printf("%lld ",res);
    }
    puts("");
    std::fflush(stdout);
    return 0;
}