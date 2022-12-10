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
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2)
    {
        int d=abs(y1-y2);
        cout<<x1+d<<' '<<y1<<' '<<x2+d<<' '<<y2<<endl;
        ep;
    }
    if(y1==y2)
    {
        int d=abs(x1-x2);
        cout<<x1<<' '<<y1+d<<' '<<x2<<' '<<y2+d<<endl;
        ep;
    }
    int d1=abs(x1-x2);
    int d2=abs(y1-y2);
    if(d1!=d2)
    {
        cout<<-1<<endl;
        ep;
    }
    cout<<x1<<' '<<y2<<' '<<x2<<' '<<y1<<endl;
    ep;
}