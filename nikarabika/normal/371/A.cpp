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
    int n, k;
    cin>>n>>k;
    const int nk=n/k;
    int a[nk][k];
    rep(i, nk)
        rep(j, k)
            cin>>a[i][j];

    int res=0;
    rep(i, k)
    {
        int c=0;
        rep(j, nk)
            if(a[j][i]==1)
                c++;
        res+=min(c, nk-c);
    }
    cout<<res<<endl;

    return 0;
}