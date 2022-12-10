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

ull res=0;

int main()
{_
    string s;
    int k;
    ll w[26], max_=0;
    cin>>s>>k;
    rep(i, 26)
    {
        cin>>w[i];
        if(w[i]>max_)
            max_=w[i];
    }
    rep(i, s.size())
        res+=w[s[i]-97]*(i+1);
    res+=(((k+s.size())*(k+s.size()+1)/2)-((s.size())*(s.size()+1)/2))*max_;
    cout<<res<<endl;
    ep;
}