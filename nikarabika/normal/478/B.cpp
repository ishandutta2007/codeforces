#include <bits/stdc++.h>

using namespace std;

#define     _               std::ios_base::Init i; std::ios_base::sync_with_stdio(false); std::cin.tie(0);
#define     FOR(i, s, e)    for(ll i=s; i<=e; i++)
#define     rep(i, t)       for(ll i=0; i<t; i++)
#define     pb              push_back
#define     mp              make_pair
#define     p1              first
#define     p2              second

typedef unsigned long long int  ull;
typedef long long int           ll;
typedef short int               si;

int main()
{_
    ull n, m;
    cin>>n>>m;
    ull x=n/m;
    cout<<((n%m)*(x)*(x+1)/2) + ( (m-(n%m)) * (x) * (x-1) / 2 )<<' '
        <<(n-m)*(n-m+1)/2<<endl;
    return 0;
}