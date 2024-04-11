#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

ll n,m;

std::vector<ll> A;
std::vector<ll> DP;



int main()
{
    ll c1,c2,c3;
    ll a,b,c,d;

    std::cin >> n;
    ll ans = 0;
    for(c1 = 0; c1< 1000008; c1++){
        DP.push_back(999999999ll);
    }
    for(c1 = 0; c1 <= n; c1++){
        if(c1 == 0){DP[c1] = 0;}
        DP[c1+1] = min(DP[c1+1] , DP[c1]+1);
        DP[c1+2] = min(DP[c1+2] , DP[c1]+1);
        DP[c1+3] = min(DP[c1+3] , DP[c1]+1);
        DP[c1+4] = min(DP[c1+4] , DP[c1]+1);
        DP[c1+5] = min(DP[c1+5] , DP[c1]+1);
    }
    std::cout << DP[n] << "\n";



    return 0;
}