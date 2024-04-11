#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

ll mod;


ll getsum(ll n){
    if (n % 2 == 0)
        return (((n/2) % mod) * 1LL * ((n+1)% mod)) % mod;
    return ((n % mod) * 1LL * (((n+1)/2) % mod)) % mod;
}

pair<ll,ll> solve(ll d,ll u,ll l,ll r,ll L,ll R){

     if (r < L || R < l || d > u)
        return mp(0,0);
//   cerr << d <<" "<<u <<" "<<l <<" "<<r<<endl;
     ll n = r-l+1;
     if (L <= l && r <= R){
        d = max(d,1LL);
        u = min(u,n);
        if (d > u)
            return mp(0LL,0LL);
        return mp((getsum(u) - getsum(d-1) + mod) % mod,(u - d + 1)%mod);
     }

     ll mid = l + ((n+1)/2) - 1;
     pair<int,int> ans1 = solve((d+2)/2    ,(u+1)/2,l    ,mid, L, R);
     pair<int,int> ans2 = solve((d+1)/2,u/2    ,mid+1,r  , L, R);
     ans1.first = (2LL*ans1.first - ans1.second + mod) % mod;
     ans2.first = (2*ans2.first) % mod;

    // cerr << d <<" "<<u <<" "<<l <<" "<<r<<"   :   "<<ans1.first <<" "<<ans1.second <<" "<<ans2.first <<" "<<ans2.second << endl;

     return mp((ans1.first + ans2.first)%mod,(ans1.second + ans2.second)%mod);
}




int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    ll n;
    ll m;
    cin >> n >> m >> mod;

    for (int i = 0; i < m; i++){
        ll l,r, u,d;
        scanf(LLD" "LLD" "LLD" "LLD,&l,&r,&d,&u);
        printf(LLD"\n",solve(d,u,1,n,l,r).first);
    }

  return 0;
}