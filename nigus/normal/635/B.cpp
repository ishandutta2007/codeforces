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

std::vector<ll> A;
std::vector<ll> B;

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,d,e,f;
    ll r;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

   std::cin >> n;
   for(c1=0;c1<n;c1++){
    std::cin >> a;
    if(a != 0){A.push_back(a);}
   }
   for(c1=0;c1<n;c1++){
    std::cin >> a;
    if(a != 0){B.push_back(a);}
   }

   a = A[0];
   b = B[0];
   c = 0;
   while(b != a){
    c++;
    b = B[c];
   }
   bool fail = 0;
   for(c1=0;c1<n-1;c1++){
        if(A[c1] != B[(c+c1)%(n-1)]){fail = 1;}

   }
   if(fail == 0){std::cout << "YES\n";}
   else{
    std::cout << "NO\n";
   }
	return 0;
}