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

typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
float likeabutterfly;
string likeabee;
ll n,m,q,h,k,w;
ll T;
string s;
bool vow(char ch){
return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y');
}

ll DP[104][104] = {0};

bool solve(ll k, ll i){

    if(DP[k][i] != -1){return DP[k][i];}

    for(ll c1 = 1; c1 <= k; c1++){

        ll a = i-c1;
        if(a == -1){DP[k][i] = 1;  return 1;}
        if(a >= 0){

            if(vow(s[a])){DP[k][i] = solve(k,a); return DP[k][i];}

        }

    }

return 0;
}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,d,e,c;
    ll x,y,z;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> s;

    for(c1 = 0; c1 < 104; c1++){
        for(c2 = 0; c2 < 104; c2++){
            DP[c1][c2] = -1;
        }
    }

    n = s.length();
    ll ans;
    for(c1 = 1; c1 < 120; c1++){
        if(solve(c1, n)){ans = c1; break;}
    }

    cout << ans << "\n";

	return 0;
}