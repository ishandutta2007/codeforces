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
ll n,m,q,T,ans;


std::vector<ll> A;
std::vector<ll> B;
std::vector<ll> F;
std::vector<ll> ANS;

string nts (ll x)
  {
     ostringstream ss;
     ss << x;
     return ss.str();
  }

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,p,q,c,d,x,f,t;
    std::cin >> n;
    ll n2=0;
    for(c1=0;c1<n;c1++)
    {
        std::cin >> a;
        A.push_back(a);
        if(c1>0)
        {

            if(a==A[c1-1])
            {

                F[n2-1]++;

            }
            else
            {
                B.push_back(a);
                F.push_back(1);
                n2++;
            }
        }
        else
        {
                B.push_back(a);
                F.push_back(1);
                n2++;
        }

    }

    ll ans = 0;
    ANS.push_back(F[0]);
    if(n2>1){ANS.push_back(F[0]+F[1]);}

    for(c1=2;c1<n2;c1++)
    {



        if(B[c1] > B[c1-2]+1 || B[c1] < B[c1-2]-1)
        {
            ANS.push_back(F[c1]+F[c1-1]);
        }
        else
            {

            ANS.push_back(ANS[c1-1]+F[c1]);
            }

    }

    for(c1=0;c1<n2;c1++)
    {

        if(ANS[c1] > ans)
        {
            ans = ANS[c1];
        }

    }
   std::cout << ans << "\n";

    return 0;
}