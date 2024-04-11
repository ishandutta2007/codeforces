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
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL

const int MAXN = 1e5 + 5;
int t[MAXN];
int a[MAXN];
int n,m;

signed main(){
    int T;scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&n,&m);CLR(t,0);
        int sm = 0,ans = 0;
        FOR(i,1,m){
            int x;scanf("%lld",&x);sm += x;
            int cnt = 0;
            while(x) x >>= 1,cnt++;cnt--;
            ++t[cnt];
        }
        if(sm < n){
            puts("-1");
            continue;
        }
        ROF(i,30,1){
            while(t[i] != 0){
                if(n >= (1ll<<i)){
                    n -= (1ll<<i);sm -= (1ll<<i);t[i]--;
                    continue;
                }
                if(sm < n+(1ll<<i)){
                    sm -= (1<<(i-1));++t[i-1];++ans;
                    if(n >= (1ll<<(i-1))) n -= ((1ll<<(i-1)));
                    t[i]--;continue;
                }
                sm -= (1ll<<i);t[i]--;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}