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

ll n,m,k;

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
    ll a,b,p,q,c;

    std::cin >> n;
    for(c1=0;c1<n;c1++)
    {


        std::cin >> a;
        A.push_back(a);

    }

ll ans = 0;
ll curr = 0;
for(c1=0;c1<n;c1++)
{

    ans += abs(A[c1]-curr);
    curr += A[c1]-curr;
}
std::cout << ans << "\n";
    return 0;
}