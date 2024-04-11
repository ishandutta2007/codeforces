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
int a[MAXN];
int n,k;
std::map<int,int> S;

inline void Solve(){
    S.clear();
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i),a[i] %= k,S[k-a[i]]++;
    LL ans = 0;bool flag = 0;
    for(auto x:S) if(x.fi%k) ans = std::max(ans,x.fi+1ll*(x.se-1)*k),flag = 1;
    printf("%lld\n",ans+(int)flag);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}