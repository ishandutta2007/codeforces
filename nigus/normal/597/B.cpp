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

std::vector<ll> A;
std::vector<ll> B;
std::vector<ll> ind;

string nts (ll x)
  {
     ostringstream ss;
     ss << x;
     return ss.str();
  }

bool comp(ll i, ll j)
{
    return B[i]<B[j];
}


int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,p,q;

    std::cin >> n;

    for(c1=0;c1<n;c1++)
    {

        std::cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
        ind.push_back(c1);
    }
std::sort(ind.begin(),ind.end(),comp);

ll ans = 0;

ll lef = -999999999999ll;

for(c1=0;c1<n;c1++)
{
    a = ind[c1];
    if(A[a] > lef)
    {
        ans++;
        lef=B[a];
    }


}

std::cout << ans << "\n";

    return 0;
}