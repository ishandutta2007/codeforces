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
    int n;
    cin>>n;
    char s[n];
    int t[n];
    cin>>s;
    rep(i, n)
        t[i]=0;
    t[0]=1;
    rep(i, n)
    {
        t[i]+=s[i]-48;
        t[i+1]+=t[i]/2;
        t[i]%=2;
    }
    int c=0;
    rep(i, n)
    {
        if(t[i]!=s[i]-48)
            c++;
    }
    cout<<c<<endl;
    ep;
}