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
    string a, b;
    cin>>a>>b;
    rep(i, a.size())
    {
        if(a[i]<97)
            a[i]+=32;
        if(b[i]<97)
            b[i]+=32;
        if(a[i]<b[i])
        {
            cout<<-1<<endl;
            ep;
        }
        else if(a[i]>b[i])
        {
            cout<<1<<endl;
            ep;
        }
    }
    cout<<0<<endl;
    ep;
}