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
#define     L               first
#define     p2              second
#define     R               second

typedef unsigned long long int  ull;
typedef long long int           ll;
typedef short int               si;

int main()
{_
    set <int> s;
    int n, m;
    cin>>n>>m;
    int a[n], b[n];
    int l[m];
    rep(i, n)
        cin>>a[i];
    rep(i, m)
        cin>>l[i];
    for(int i=n-1; i>=0; i--)
    {
        s.insert(a[i]);
        b[i]=s.size();
    }
    for(int i=0; i<m; i++)
        cout<<b[l[i]-1]<<endl;
    ep;
}