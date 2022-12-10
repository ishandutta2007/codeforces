#include <bits/stdc++.h>

using namespace std;

#define     _               std::ios_base::Init i; std::ios_base::sync_with_stdio(false); std::cin.tie(0);
#define     All(a)          a.begin(), a.end()
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
{_
    int n;
    cin>>n;
    bool x=false;
    int a[n], b[n];
    rep(i, n)
    {
        cin>>a[i]>>b[i];
        if(a[i]!=b[i])
            x=true;
    }

    hello:
    if(x)
        cout<<"Happy Alex"<<endl;
    else
        cout<<"Poor Alex"<<endl;
    ep;
}