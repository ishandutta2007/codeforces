#include <bits/stdc++.h>

using namespace std;

#define     _               std::ios_base::Init i; std::ios_base::sync_with_stdio(false); std::cin.tie(0);
#define     FOR(i, s, e)    for(ll i=s; i<=e; i++)
#define     rep(i, t)       for(ll i=0; i<t; i++)
#define     sp              system("pause")
#define     ep              return 0
#define     cendl           cout<<endl
#define     pb              push_back
#define     pob             pop_back

typedef unsigned long long int  ull;
typedef long long int           ll;
typedef short int               si;

int main()
{
    _
    int n;
    cin>>n;
    int x=1;
    FOR(i, 1, n/2)
    {
        rep(j, (n-x)/2)
            cout<<'*';
        rep(j, x)
            cout<<'D';
        rep(j, (n-x)/2)
            cout<<'*';
        cendl;
        x+=2;
    }
    rep(i, n)
        cout<<'D';
    cendl;
    FOR(i, 1, n/2)
    {
        x-=2;
        rep(j, (n-x)/2)
            cout<<'*';
        rep(j, x)
            cout<<'D';
        rep(j, (n-x)/2)
            cout<<'*';
        cendl;
    }
    ep;
}