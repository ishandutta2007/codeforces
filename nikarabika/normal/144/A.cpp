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

int score(string s, int i);

int main()
{_
    int n;
    cin>>n;
    int a[n];
    rep(i, n)
        cin>>a[i];
    int max_i, min_i;
    int max_=0, min_=1000;
    rep(i, n)
    {
        if(a[i]>max_)
        {
            max_=a[i];
            max_i=i;
        }
    }
    int res=max_i;
    rep(i, n)
    {
        if(a[i]<=min_)
        {
            min_=a[i];
            min_i=i;
        }
    }
    res+=n-min_i-1;
    if(max_i>min_i)
        res--;
    cout<<res<<endl;
    ep;
}