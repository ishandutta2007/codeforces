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
ll n,m,k,q,d,h;
//ll T;

std::vector<ll> A;
std::vector<ll> B;

std::vector<ll> toobig;

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,e;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

   std::cin >> n >> k;
    n++;


   for(c1 = 0; c1 < n; c1++){

    std::cin >> a;
    A.push_back(a);
    toobig.push_back(1);
    B.push_back(-1);

   }
    ll nu = 0;
    ll stor = 1000000000000000000ll;
    for(c1 = n-1; c1 >= 0; c1--){
        nu += A[c1];
        if(nu <= stor && nu >= -stor){
            B[c1] = nu;
            toobig[c1] = 0;
            nu *= 2;
        }
        else{break;}
    }

    x = 0;
    ll ans = 0;

    for(c1 = 0; c1 <n; c1++){

        if(toobig[c1] == 0){
            //cout << c1 << " x: " << x << "  b: " << B[c1] << "\n";
            if(B[c1] != x){

                a = B[c1]-A[c1];
                //cout << c1 << "   " << abs(a-x) << "\n";
                if(abs(a-x) <= k && (c1 != n-1 || abs(a-x) != 0)){
                    ans++;
                }

            }
        }

        if((x - A[c1])%2 == 0){
            x = (x-A[c1])/2;
        }
        else{break;}

    }

std::cout << ans << "\n";

	return 0;
}