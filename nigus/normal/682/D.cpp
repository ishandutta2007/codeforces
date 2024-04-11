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

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
float likeabutterfly;
string likeabee;
ll n,m,q,d,h,k,w,x;
//ll T;

string s,t;
ll DP[1001][1001][11][2];

ll dp(ll a, ll b, ll np, bool add){

if(a == n || b == m){return -999999999 * (np !=  k);}
if(np == k && add == 1){return 0;}
if(np > k){return -9999999999;}
if(DP[a][b][np][add] != -1){return DP[a][b][np][add];}
ll ans = 0;
ll ans2 = -9999999999;
if(s[a] == t[b]){ans2 = max(1ll + dp(a+1,b+1,np+add,0) , 1ll + dp(a+1,b+1,np+1,0));}
ans = max(dp(a+1,b,np,1) , dp(a,b+1,np,1));

ans = max(ans,ans2);

DP[a][b][np][add] = ans;
return ans;

}


int main()
{
   ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll y,z;
    //freopen("stupd.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> m >> k;
    cin >> s >> t;
    for(c1 = 0; c1 < 1001; c1++){
        for(c2 = 0; c2 < 1001; c2++){
            for(c3 = 0; c3 < 11; c3++){
                DP[c1][c2][c3][0] = -1;
                DP[c1][c2][c3][1] = -1;
            }
        }
    }

    cout << dp(0,0,0,1) << "\n";

	return 0;

}