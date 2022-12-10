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
#define     mp              make_pair
#define     p1              first
#define     p2              second

typedef unsigned long long int  ull;
typedef long long int           ll;
typedef short int               si;

int main()
{_
    int n;
    cin>>n;
    si a[n+2][n+2];

    rep(i, n)
        rep(j, n)
            a[i+1][j+1]=0;

    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            char x;
            cin>>x;
            if(x=='o')
            {
                a[i-1][j]++;
                a[i+1][j]++;
                a[i][j-1]++;
                a[i][j+1]++;
            }
        }
    }

    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            if(a[i][j]%2==1)
            {
                cout<<"NO"<<endl;
                ep;
            }
        }
    }
    cout<<"YES"<<endl;

    ep;
}