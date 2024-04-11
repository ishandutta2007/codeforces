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

ll n,m,q;
std::vector<ll> A;
std::vector<ll> ind;

string nts (ll x)
  {
     ostringstream ss;
     ss << x;
     return ss.str();
  }
bool comp(ll i, ll j)
{

    return A[i] < A[j];


}


int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,p,q,c,d;

    std::cin >> n;

    for(c1=0;c1<n;c1++)
    {

        std::cin >> a;
        A.push_back(a);
        ind.push_back(c1);

    }

    std::stable_sort(ind.begin(),ind.end(),comp);

    ll ans = 0;
    ll l=0;

    for(c1=0;c1<n;c1++)
    {

        if(ind[c1] > l){l = ind[c1];}
        else{
            if(c1==l){ans++;l++;}
        }

    }
   std::cout << ans << "\n";
    return 0;
}