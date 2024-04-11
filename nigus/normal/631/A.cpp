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
ll T;

std::vector<ll> A;
std::vector<ll> B;


int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,e;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::cin >> n;
    for(c1=0;c1<n;c1++){
        std::cin >> a;
        A.push_back(a);
    }
     for(c1=0;c1<n;c1++){
        std::cin >> a;
        B.push_back(a);
    }
    ll ans = 0;
    ll temp;
    ll a1,a2;
    for(c1 = 0; c1 < n; c1++){
        temp = 0;
        a1 = 0;
        a2 = 0;
        for(c2 = c1; c2 <n; c2++){
            a1 = a1 | A[c2];
            a2 = a2 | B[c2];
            if(a1+a2 > ans){ans = a1+a2;}
        }


    }
    std::cout << ans << "\n";


	return 0;
}