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
    int n, m;
    cin>>n>>m;
    char h1, h2;
    cin>>h1;
    rep(i, n-2)
    {
        char c;
        cin>>c;
    }
    cin>>h2;

    char v1, v2;
    cin>>v1;
    rep(i, m-2)
    {
        char c;
        cin>>c;
    }
    cin>>v2;
    if(h1==h2 || v1==v2)
        cout<<"NO"<<endl;
    else if(h1=='>' && v2=='^')
            cout<<"NO"<<endl;
    else if(h1=='<' && v1=='^')
            cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}