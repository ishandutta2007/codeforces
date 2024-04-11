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
    int n;
    cin>>n;
    int a[n];
    rep(i, n)
        cin>>a[i];
    set <int> s;
    s.insert(a[0]);
    FOR(i, 1, n-1)
    {
        if(s.upper_bound(a[i])!=s.end())
            s.erase(s.upper_bound(a[i]));
        s.insert(a[i]);
    }
    cout<<s.size()<<endl;
    return 0;
}