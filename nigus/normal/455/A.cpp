#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

ll n,m;

std::vector<ll> A;
std::vector<ll> B;
std::vector<ll> DP;

ll dp(ll i){
if(i > 100000){return 0;}
if(DP[i] != -1){return DP[i];}
ll a,b,c;
a = dp(i+1);
b = B[i]*i + dp(i+2);
DP[i] = max(a,b);
return DP[i];

}

int main()
{
    ll c1,c2,c3;
    ll a,b,c,d;

    std::cin >> n;
    ll ans = 0;
    for(c1 =0; c1 <= 100000; c1++){
        B.push_back(0);
        DP.push_back(-1);
    }
    for(c1=0;c1<n;c1++){

        std::cin >> a;
        B[a]++;
    }
    std::cout << dp(0) <<"\n";
    return 0;
}