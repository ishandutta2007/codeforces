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
std::vector<ll> B;

string nts (ll x)
  {
     ostringstream ss;
     ss << x;
     return ss.str();
  }


ll lis()
{

    std::vector<ll> B;
    ll a,b,c;
    return 0;


}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,q,c,d,x,f,l;


    std::cin >> n;

    for(c1=0;c1<n;c1++)
    {

        std::cin >> a;
        A.push_back(a);
        B.push_back(0);
    }

    ll ans = 0;

    ll nu=0;
    ll ma = 0;
    for(c1=0;c1<n;c1++)
    {

        if(A[c1] == 0){B[A[c1]] = 1;}
        else{
            B[A[c1]] = B[A[c1]-1]+1;
        }
        if(B[A[c1]] > ma){ma = B[A[c1]];}

    }

    ans = n-ma;
    std::cout << ans << "\n";


    return 0;
}