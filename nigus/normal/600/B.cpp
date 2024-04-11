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
std::vector<ll> inda;
std::vector<ll> indb;

std::vector<ll> svar;

bool compa(ll i, ll j)
{


    return A[i] <A[j];

}

bool compb(ll i, ll j)
{


    return B[i] <B[j];

}

string nts (ll x)
  {
     ostringstream ss;
     ss << x;
     return ss.str();
  }


int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,q,c,d,x,f,t,l,r;
std::cin >> n >> m;

for(c1=0;c1<n;c1++)
{
    std::cin >> a;
    A.push_back(a);
    inda.push_back(c1);
}

A.push_back(100000000000ll);
inda.push_back(n);
for(c1=0;c1<m;c1++)
{
    std::cin >> a;
    B.push_back(a);
    svar.push_back(0);
    indb.push_back(c1);
}


std::sort(inda.begin() , inda.end() , compa);
std::sort(indb.begin() , indb.end() , compb);

ll p = 0;

for(c1=0;c1<m;c1++)
{
    a = indb[c1];


    while(B[a] >= A[inda[p]])
    {
        p++;
    }
    svar[a] = p;
}

for(c1=0;c1<m;c1++)
{
    std::cout << svar[c1] << " ";
}


    return 0;
}