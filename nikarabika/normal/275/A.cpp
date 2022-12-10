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

si s[5][5];

int main()
{_
    rep(i, 3)
    {
        rep(j, 3)
        {
            int a;
            cin>>a;
            s[i+1][j+1]=a%2;
        }
    }
    si a[5][5];
    rep(i, 5)
        rep(j, 5)
            a[i][j]=true;
    FOR(i, 1, 3)
    {
        FOR(j, 1, 3)
        {
            if(s[i][j])
            {
                a[i][j]= (1+a[i][j])%2;
                a[i-1][j]= (1+a[i-1][j])%2;
                a[i+1][j]= (1+a[i+1][j])%2;
                a[i][j-1]= (1+a[i][j-1])%2;
                a[i][j+1]= (1+a[i][j+1])%2;
            }
        }
    }
    FOR(i, 1, 3)
    {
        FOR(j, 1, 3)
            cout<<a[i][j];
        cendl;
    }
    ep;
}