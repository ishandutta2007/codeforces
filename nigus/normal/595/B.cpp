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

ll big = 1000000007ll;
ll bp = 1168195727ll;

ll n,m,k;
ll tk,nk;
std::vector<ll> A;
std::vector<ll> B;

string nts (ll x)
  {
     ostringstream ss;
     ss << x;
     return ss.str();
  }

  ll many(ll s , ll x)
  {
      return ll(s/x)+1;
  }

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,p,q;

    std::cin >> n >> k;
   nk=round(n/k);
   for(c1=0;c1<nk;c1++)
   {
       std::cin >> a;
       A.push_back(a);
   }

    for(c1=0;c1<nk;c1++)
   {
       std::cin >> b;
       B.push_back(b);
   }

   tk = 1;
   for(c1=0;c1<k-1;c1++)
   {
       tk*=10;
   }

   ll ans = 1;

   for(c1=0;c1<nk;c1++)
   {

       a = many(tk*10-1,A[c1]);
       p = B[c1]*tk;
       q = (B[c1]+1)*tk-1;
       b = many(q-(p-p%A[c1]) , A[c1])-1;
       if(p%A[c1] == 0){b++;}
       ans *= (a-b);
       if(ans > big){ans %= big;}


   }
   std::cout << ans << "\n";

    return 0;
}