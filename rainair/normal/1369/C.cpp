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
int n,k;
int a[MAXN],w[MAXN];

inline void Solve(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,k) scanf("%d",w+i),w[i]--;
    std::sort(a+1,a+n+1);std::reverse(a+1,a+n+1);std::sort(w+1,w+k+1);
    LL ans = 0;
    FOR(i,1,k) ans += 1ll*(w[i]==0?2:1)*a[i];
    int l = k+1;
    FOR(i,1,k){
        if(!w[i]) continue;
        int r = l+w[i]-1;
        ans += a[r];
        l = r+1;
    }
    printf("%lld\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}