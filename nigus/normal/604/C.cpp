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

    string s;

    std::cin >> n;
    std::cin >> s;

    ll ans=1;
    ll fail = 0;
    ll de=1;
    for(c1=1;c1<n;c1++)
    {
        if(s[c1] != s[c1-1]){ans++;de=1;}
        else{fail+=de;de=1;}

    }
    if(fail >2){fail=2;}
    std::cout << ans + fail << "\n";

    return 0;
}