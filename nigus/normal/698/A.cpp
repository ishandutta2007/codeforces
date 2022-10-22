#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
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
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
float likeabutterfly;
string likeabee;
ll n,m,q,h,k,w;
ll T;

vector<ll> A;
ll DP[4][1000] = {-1};

ll dp(ll b, ll i){

if(i >= n){return 0;}

if(DP[b][i] != -1){return DP[b][i];}

ll x,y,z;

ll ans = n;

for(ll c1 = 0; c1 < 3; c1++){


    if((c1 & b) == 0 && (c1 & A[i]) == c1){
        ans = min(ans, (c1==0) + dp(c1,i+1));
    }
}
DP[b][i] = ans;
return ans;

}


int main()
{
   ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll y,z;
    //freopen("stupd.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n;
    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }
    for(c1 = 0; c1 < 4; c1++){
        for(c2 = 0 ;c2 < 1000; c2++){
            DP[c1][c2] = -1;
        }
    }
    cout << dp(0,0) << "\n";

	return 0;

}