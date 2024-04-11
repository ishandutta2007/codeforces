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
    int a[2*n];
    rep(i, n)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    int x, y;
    cin>>x>>y;
    if(x>y)
        swap(x, y);
    int s1=0, s2=0;
    FOR(i, x-1, y-2)
        s1+=a[i];
    FOR(i, y-1, x+n-2)
        s2+=a[i];
    cout<<min(s1, s2)<<endl;
    ep;
}