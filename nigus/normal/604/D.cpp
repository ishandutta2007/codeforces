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
ll n,r,p,m,q,k;




std::vector<ll> A;
std::vector<ll> mark;

string nts (ll x)
  {
     ostringstream ss;
     ss << x;
     return ss.str();
  }


ll fac(ll i)
{
    ll ans = 1;
    for(ll c=1; c<=i;c++)
    {
        ans *= c;
        ans %= big;

    }
    return ans;
}


int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,q,c,d,x,f,l;
    ll ma=0;

    std::cin >> p >> k;



        ll ans=1;
        for(c1=0;c1<p;c1++)
        {
            mark.push_back(0);
        }
        for(c1=1;c1<p;c1++)
        {

            if(mark[c1] == 0)
            {

                c2 = (c1*k)%p;
                while(mark[c2] == 0)
                {
                    mark[c2] = 1;
                    c2=(c2*k)%p;
                }
                ans *= p;
                if(ans>=big){ans%=big;}

            }

        }
if(k == 1)
{
    ans *=p;
    ans%=big;
}
std::cout << ans << "\n";



    return 0;
}