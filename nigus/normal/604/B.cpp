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
#include <locale>
#include <sstream>


using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll bp = 1168195727ll;
ll n,r,p,m,q;




std::vector<ll> A;

string nts (ll x)
  {
     ostringstream ss;
     ss << x;
     return ss.str();
  }



int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,q,c,d,x,f,l,k;
    ll ma=0;
    std::cin >> n>> k;
    if(k>n){k=n;}
    for(c1=0;c1<n;c1++)
    {

        std::cin >> a;
        A.push_back(a);
        if(a>ma){ma=a;}

    }

    ll ans = ma;


    a = n-k;
    b = 2*k-n;
    for(c1 = 0; c1 < a;c1++)
    {
        c = A[2*a-c1-1] + A[c1];
        if(c > ans){ans = c;}

    }

    for(c1 = 2*a; c1<n;c1++)
    {
        c = A[c1];
        if(c > ans){ans = c;}

    }
std::cout << ans << "\n";


    return 0;
}