/*
 * Author: RainAir
 * Time: 2019-08-27 21:31:06
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
const int ha = 1e9 + 7;

int prime[MAXN],mu[MAXN],tot;
int p[MAXN];

inline void prepare(){
    mu[1] = 1;
    FOR(i,2,MAXN-1){
        if(!p[i]) prime[++tot] = i,mu[i] = -1;
        for(int j = 1;j <= tot && i*prime[j] < MAXN;++j){
            p[i*prime[j]] = true;
            if(!(i%prime[j])){
                mu[i*prime[j]] = 0;
                break;
            }
            mu[i*prime[j]] = -mu[i];
        }
    }
}

inline int qpow(int a,int n){
    int res = 1;
    while(n){
        if(n & 1) res = 1ll*res*a%ha;
        a = 1ll*a*a%ha;
        n >>= 1;
    }
    return res;
}

int a[MAXN],cnt[MAXN];
int n;

signed main(){
    scanf("%lld",&n);prepare();
    FOR(i,1,n){
        int x;scanf("%lld",&x);
        int q = std::sqrt(1.0*x);
        FOR(i,1,q){
            if(!(x%i)){
                cnt[i]++;
                if(x/i != i) cnt[x/i]++;
            }
        }
    }
    int ans = 0;
    FOR(i,1,100000) (ans = (ans+(qpow(2,cnt[i])+ha-1)%ha*mu[i]+ha)%ha);
    printf("%lld\n",ans);
    return 0;
}