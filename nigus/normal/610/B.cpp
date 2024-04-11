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
ll big = 1000000007ll;
ll n,m;

std::vector<ll> A;

int main()
{
    ll c1,c2,c3,c4,c5;
    ll a,b,c,d,e,f;
    ll x,y,z;

    std::cin >> n;
    ll mi = 9999999999999ll;
    for(c1=0;c1<n;c1++){
        std::cin >> a;
        A.push_back(a);
        if(a<mi){mi=a;}
    }

    for(c1=0;c1<n;c1++){

        A.push_back(A[c1]);

    }
    ll ma = 0;
    ll nu = 0;
    for(c1=0;c1<2*n;c1++){

       if(A[c1] == mi){
        if(nu>ma){ma=nu;}nu=0;
       }
       else{nu++;}


    }

    ll ans = mi*n+ma;
    std::cout << ans << "\n";
	return 0;
}