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

ll n,m,k;

std::vector<std::vector<ll> > C(200004 , std::vector<ll>());
std::vector<ll> X;
std::vector<ll> Y;
std::vector<ll> W;


string nts (ll x)
  {
     ostringstream ss;
     ss << x;
     return ss.str();
  }

bool comp(ll i, ll j)
{
    return X[i] > X[j];
}

ll findmax(ll s)
{
    if(s+100000<0 || s+100000>=200004){return -1;}
    if(C[s+100000].size()<=0){return -1;}
    ll l = C[s+100000].size();
    return C[s+100000][l-1];
}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,p,q,c;

    std::cin >> n;

    for(c1=0;c1<n;c1++)
    {

        std::cin >> a >> b;
        X.push_back(a);
        Y.push_back(b);
        C[b-a+100000].push_back(c1);
    }

    for(c1=0;c1<n;c1++)
    {

        std::cin >> a;
        W.push_back(a);

    }

    for(c1=0;c1<200004;c1++)
    {
        if(C[c1].size()>0)
        {
            std::sort(C[c1].begin(),C[c1].end(),comp);
        }

    }

    bool fail=0;
    std::vector<ll> A;

    for(c1=0;c1<n;c1++)
    {
        a = findmax(W[c1]);
        b = findmax(W[c1]+1);
        c = findmax(W[c1]-1);
       // std::cout << a << "\n";
        A.push_back(a);
        if(a==-1){fail=1;}
        else
            {

            if(b != -1)
            {
                if(X[b] < X[a]){fail=1;}
            }

            if(c != -1)
            {
                if(X[c] <= X[a]){fail=1;}
            }

            }
        if(C[W[c1]+100000].size() > 0){
        C[W[c1]+100000].pop_back();}

    }

    if(fail==0)
    {
        std::cout << "YES\n";
        for(c1=0;c1<n;c1++)
        {

            std::cout << X[A[c1]] << " " << Y[A[c1]] << "\n";

        }
    }else
    {
        std::cout << "NO\n";
    }


    return 0;
}