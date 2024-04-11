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

using namespace std;
typedef long long ll;

ll big = 1000000007ll;
ll bp = 1168195727ll;

std::vector<ll> A;
std::vector<ll> B;

std::vector<ll> P;
std::vector<ll> Q;

ll n,m,x1,x2;
long double eps = 0.00000000001;

bool comp1(ll i, ll j)
{

    return ((P[i]*(x1+eps) + Q[i]) > (P[j]*(x1+eps) + Q[j]));

}

bool comp2(ll i, ll j)
{

    return ((P[i]*(x2-eps) + Q[i]) > (P[j]*(x2-eps) + Q[j]));

}


int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b;


    std::cin >> n;
    std::cin >> x1 >> x2;

    for(c1=0;c1<n;c1++)
    {

        std::cin >> a >> b;
        A.push_back(c1);
        B.push_back(c1);
        P.push_back(a);
        Q.push_back(b);

    }
      std::sort(A.begin(),A.end(),comp1);
      std::sort(B.begin(),B.end(),comp2);

      bool fail=0;
      for(c1=0;c1<n;c1++)
      {


        a=A[c1];
        b=B[c1];
       // std::cout<<setprecision(18) << a << " " << b << "     " << (P[c1]*x1 + Q[c1] + P[c1]*eps)<< "\n";
          if(a!=b){fail=1;}

      }
if(fail==0){std::cout << "NO\n";}else{std::cout << "YES\n";}

    return 0;
}