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

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll n,m,k,q;
ll T;


//ll DP[5000][5000] = {-1};

std::vector<std::vector<ll> > DP(4001 , std::vector<ll>());

ll dp(ll kd , ll nd){
if(kd < 0){return 0;}
if(kd > 2000){return 0;}
//cout << DP[kd+3000][nd];
if(DP[kd][nd] != -1){return DP[kd][nd];}
if(nd == 0 && kd == 0){return 1;}
if(nd == 0 && kd != 0){return 0;}
ll an = (dp(kd-1,nd-1) + dp(kd+1,nd-1))%big;
//if(nd == 1){an = dp(kd+1,nd-1)%big;}
DP[kd][nd] = an;
return an;
}

int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s;
    std::cin >> n >> m;
    std::cin >> s;
    a  = 0;
    ll m1 = 0;
    for(c1=0;c1<4001;c1++){
        for(c2=0;c2<4001;c2++){
            DP[c1].push_back(-1);
        }
    }
    for(c1=0;c1<m;c1++){
        if(s[c1] == '('){a--;}else{a++;}
        m1 = max(m1,a);
    }
    ll m2 = m1-a;
    //std::cout << dp(1,3) << "\n";

    for(c1 = 0; c1 < 4000; c1++){dp(c1,n-m);}
    ll ans = 0;
    for(c1 = 0; c1<=n-m;c1++){
        for(c2 = 0; c2<=n-m;c2++){
            ans += (dp(m1+c2,c1) * dp(m2+c2,n-m-c1))%big;
            //cout << m1+c2 << " " << c1 << "  -  " << m2+c2 << " " << n-m-c1 << "\n";
            ans %= big;
        }
    }
    std::cout << ans << "\n";

	return 0;
}