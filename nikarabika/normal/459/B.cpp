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

map <ll, ll> a;

int main()
{_
    int n;
    ll max_=0, min_=0;
    cin>>n;
    rep(i, n)
    {
        ll x;
        cin>>x;
        if(i==0)
        {
            max_=x;
            min_=x;
        }
        if(x<min_)
            min_=x;
        else if(x>max_)
            max_=x;
        a[x]++;
    }
    cout<<max_-min_<<' ';
    if(max_==min_)
        cout<<(a[max_]*(a[max_]-1))/2<<endl;
    else
        cout<<a[max_]*a[min_]<<endl;
    ep;
}