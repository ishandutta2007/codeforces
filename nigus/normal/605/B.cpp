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

std::vector<ll> W;
std::vector<ll> med;
std::vector<ll> ind;
std::vector<ll> A;
std::vector<ll> B;

ll nkant;

string nts (ll x)
  {
     ostringstream ss;
     ss << x;
     return ss.str();
  }

bool comp(ll i,ll j)
{
    if(W[i] == W[j])
    {
        return med[i] > med[j];
    }
    return W[i] < W[j];

}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,q,c,d,x,f,l,y;


    std::cin >> n >> m;
    bool fail=0;
    for(c1=0;c1<m;c1++)
    {
        std::cin >> a >> b;
        W.push_back(a);
        med.push_back(b);
        ind.push_back(c1);
        A.push_back(-1);
        B.push_back(-1);
    }

std::sort(ind.begin(),ind.end(),comp);
x = 1;
y = 2;
nkant=0;

for(c1=0;c1<m;c1++)
{
    a = ind[c1];
    if(med[a] == 1)
    {
        nkant++;
        A[a] = 0;
        B[a] = nkant;
    }
    else
    {

        if(y > nkant){fail=1;}
        A[a] = x;
        B[a] = y;
        if(x+1==y){y++;x=1;}
        else{x++;}

    }


}

if(fail==1)
{
    std::cout << -1 << "\n";
}
else
{

    for(c1=0;c1<m;c1++)
    {

        std::cout << A[c1]+1 << " " << B[c1]+1 << "\n";

    }

}


    return 0;
}