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

ll g = 2000000ll;

std::vector<ll> A;
std::vector<ll> B;
std::vector<ll> ind;

string nts (ll x)
  {
     ostringstream ss;
     ss << x;
     return ss.str();
  }


ll p1(ll x)
{
    return (x*x*x-x);
}

ll p2(ll x)
{
    return (3*x*x+3*x);
}

bool comp(ll i, ll j)
{

    if(A[i] != A[j]){return A[i] < A[j];}
    else{return B[i] < B[j];}


}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,p,q,c,d;

    std::cin >> n;

    ll n2 = 6*n;
    ll ans =0;
    ll y;
    for(ll x = 1; x < g; x++)
    {

        a = p1(x);
        b = p2(x);
        //std::cout << a << " " << b << " " << x << "\n";

        if((n2+a)%b == 0)
        {
            y = ((n2+a)/b);
            if(y > x){ans+=2;

            B.push_back(x);
            A.push_back(y);

            B.push_back(y);
            A.push_back(x);

            ind.push_back(ans-2);
            ind.push_back(ans-1);

            }

            if(x == y)
            {
                ans++;
                B.push_back(x);
                A.push_back(y);
                ind.push_back(ans-1);
            }

        }
    }

    std::sort(ind.begin(),ind.end(),comp);
std::cout << ans << "\n";

for(c1=0;c1<ans;c1++)
{

    std::cout << A[ind[c1]] << " " << B[ind[c1]] << "\n";

}
    return 0;
}