#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <random>
#include <chrono>
#include <bitset>
#include <fstream>
#include <sstream>

using namespace std;
using namespace std::chrono;

/*
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
*/

typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll n,m,k,r;


vector<ll> P;

ll mark[100000] = {0};

bool f(ll wins, ll plays){
    //cout << wins << " " << plays << "\n";
   // if(wins < 0)return 0;
    if(plays == 0)return wins <= 0;
    if(plays == 1)return (wins <= 0);
    if(plays % 2 == 0)return f(wins-1 , plays/2);
    return (f(wins-1 , plays/2+1) & f(wins-2 , plays/2));
}


ll bs(){
ll l = 1;
ll r = n;
while(l < r-1){

    ll mid = (l+r)/2;

    if(f(mid , n)){

        l = mid;

    }
    else{
        r = mid;
    }
}
return l;
}

ll DP[1000] = {0};

ll dp(ll i){
if(i == 1)return 2;
if(i == 2)return 3;
if(DP[i] != 0)return DP[i];
DP[i] = dp(i-1)+dp(i-2);
return DP[i];
}

ll ugly(ll i){

ll ans = 0;
ll i2 = i;
if(i == 2)return 1;

    while(i2 > 1){

        i2 += i2%3;
        i2/=3;
        ans+=2;

    }

return ans;
}



int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll c1,c2,c3;
    ll a,b,c,e;

    cin >> n;

    ll t = 1;
/*
    for(ll c2 = 2; c2 < 10000; c2++){
    ll ma = 1;

    n = c2;
    for(c1 = 1; c1 < 60; c1++){
        if(f(c1 , n))ma = c1;
    }

   if(ugly(c2) != ma){cout << ugly(c2) << "  " << ma << "\n";}
  // t*= 2;
    }
*/
    ll ans = 1;
    for( c1 = 1; c1 <= n; c1++){

        //cout << dp(c1) << " " << n << "\n";
        if(dp(c1) > n){ans = c1-1;break;}

    }

    cout  << ans << "\n";


    return 0;
}