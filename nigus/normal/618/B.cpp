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

std::vector<std::vector<ll> > C(1000 , std::vector<ll>());
std::vector<std::vector<ll> > A(1000 , std::vector<ll>());
std::vector<ll> P;

int main()
{
    ll c1,c2,c3,c4,c5;
    ll a,b,c,d,e,f;
    ll x,y,z;

    std::cin >> n;

    for(c1 = 0;c1 < n+1; c1++){
        for(c2 = 0; c2 < n+1 ;c2++){
            C[c1].push_back(0);
        }
    }

    for(c1 = 0;c1 < n; c1++){
        P.push_back(-1);
        for(c2 = 0; c2 < n ;c2++){
            std::cin >> a;
            A[c1].push_back(a);
            if(a != 0){
            C[c1][a]++;}
        }
    }

    for(c1 = 0; c1<n;c1++){
        for(c2 = 0; c2<n;c2++){
            if(C[c2][c1+1] == n-c1-1 && P[c2] == -1)
            {
                P[c2] = c1+1;
                break;
            }
        }
    }

    for(c1 = 0; c1<n;c1++){
        std::cout << P[c1] << " ";
    }


	return 0;
}