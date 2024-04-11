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
std::vector<ll> R;
std::vector<ll> R1;
std::vector<ll> mode;
std::vector<ll> mode1;

ll nr;

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,e;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

   std::cin >> n >> m;

   for(c1=0;c1<n;c1++){
    std::cin >> a;
    A.push_back(a);
   }

   for(c1=0;c1<m;c1++){
    std::cin >> a >> b;
    mode1.push_back(a);
    R1.push_back(b);
   }

   nr = 0;

   ll ma = 0;
   for(c1 = m-1; c1>=0;c1--){
    if(R1[c1] > ma){
            ma = R1[c1];
            nr++;
            R.push_back(ma);
            mode.push_back(mode1[c1]);
            //std::cout << mode1[c1] << "   " << R1[c1] << "\n";
            }
   }

   x = R[nr-1];

   std::vector<ll> A2;

   for(c1=0;c1<x;c1++){
    A2.push_back(A[c1]);
   }

   std::sort(A2.begin() , A2.end());

   std::vector<ll> A3;
   a = 0;
   b = x-1;

   for(c1 = nr-1; c1>=0;c1--){
    ll delt;
    if(c1 > 0){delt = R[c1] - R[c1-1];}
    else{delt = R[c1];}

    if(mode[c1] == 2){
        for(c2 = a; c2 < delt+a; c2++){
            A3.push_back(A2[c2]);

        }
        a += delt;
    }
    else{
        for(c2 = b; c2 > b-delt; c2--){
            A3.push_back(A2[c2]);
        }
        b -= delt;
    }
   }



   for(c1 = x-1; c1 >= 0; c1--){
    std::cout << A3[c1] << " ";
   }
   for(c1 = x; c1<n;c1++){
    std::cout << A[c1] << " ";
   }


	return 0;
}