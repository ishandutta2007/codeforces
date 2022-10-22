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

vector<string> S;
vector<string> SR;

vector<ll> C;

ll DP[2][100001] = {0};

string rev(string s){
    string ans = "";
    for(ll c1 = s.length()-1; c1 >= 0; c1--){
        ans += s[c1];
    }
    return ans;
}


ll dp(ll r, ll i){

if(i == n-1){return 0;}
if(DP[r][i] != -1){return DP[r][i];}

string s;
if(r == 0){s = S[i];}
else{s = SR[i];}

ll ans = 99999999999999999ll;

if(s <= S[i+1]){
    ans = min(ans, dp(0,i+1));
}
if(s <= SR[i+1]){
    ans = min(ans, dp(1,i+1) + C[i+1]);
}

DP[r][i] = ans;
return ans;

}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll y,z;
    //freopen("stress.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s;
    cin >> n;
    for(c1 = 0; c1 <n; c1++){
        cin >> a;
        C.push_back(a);
    }
    for(c1 = 0; c1 < n; c1++){
        cin >> s;
        S.push_back(s);
        SR.push_back(rev(s));
        DP[0][c1] = -1;
        DP[1][c1] = -1;
    }

    ll ans = min(dp(0,0), C[0]+dp(1,0));

    if(ans != 99999999999999999ll){
        cout << ans << "\n";
    }
    else{
        cout << "-1\n";
    }

	return 0;
}