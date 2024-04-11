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
ll n,m,k,q,d;
//ll T;

std::vector<ll> P;
std::vector<ll> T;
int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,e;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::cin >> n >> c;
    for(c1 = 0; c1 < n; c1++){
        std::cin >> a;
        P.push_back(a);
    }
    for(c1 = 0; c1 < n; c1++){
        std::cin >> a;
        T.push_back(a);
    }
    ll a1 = 0;
    ll a2 = 0;

    ll t = 0;
    for(c1 = 0; c1 < n; c1++){
        t += T[c1];
        a1 += max(0ll,P[c1] - c*t);
    }
    t = 0;
    for(c1 = 0; c1 < n; c1++){
        c2 = n-c1-1;
        t += T[c2];
        a2 += max(0ll,P[c2] - c*t);
    }
   if(a1 == a2){
    std::cout << "Tie\n";
   }
   if(a1 > a2){
    std::cout << "Limak\n";
   }
   if(a1 < a2){
    std::cout << "Radewoosh\n";
   }
	return 0;
}