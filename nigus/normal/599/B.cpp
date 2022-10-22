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
std::vector<ll> B;
std::vector<ll> F;
std::vector<ll> ind;

std::vector<ll> deg;
std::vector<std::vector<ll> > C(200001 , std::vector<ll>());

string nts (ll x)
  {
     ostringstream ss;
     ss << x;
     return ss.str();
  }



int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,p,q,c,d;

    std::cin >> m >> n;

    for(c1=0;c1<m+1;c1++)
    {

        deg.push_back(0);

    }

    for(c1=0;c1<m;c1++)
    {
        std::cin >> a;
        F.push_back(a);
        deg[a]++;
        C[a].push_back(c1);
    }

    bool fail=0;
    bool amb=0;

    for(c1=0;c1<n;c1++)
    {
        std::cin >> a;
        B.push_back(a);
        if(deg[a] == 0){fail=1;}
        if(deg[a] > 1){amb = 1;}
        else{

        if(deg[a] > 0){A.push_back(C[a][0]);}

        }
    }

    if(fail==0 && amb==0)
    {

        std::cout << "Possible\n";
        for(c1=0;c1<n;c1++)
        {
            std::cout << A[c1]+1 << " ";
        }

    }
    else{

        if(fail==1)
        {

            std::cout << "Impossible\n";

        }
        else{

            std::cout << "Ambiguity\n";
        }
    }




    return 0;
}