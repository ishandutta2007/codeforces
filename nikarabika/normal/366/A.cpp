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
    int min_[2]={999999, 999999};
    int min_post=-1;
    rep(i, 4)
    {
        int a, b, x, y;
        cin>>a>>b;
        x=min(a, b);
        cin>>a>>b;
        y=min(a, b);
        if(x+y<min_[0]+min_[1] && x+y<=n)
        {
            min_[0]=x;
            min_[1]=y;
            min_post=i+1;
        }
    }
    if(min_post==-1)
        cout<<-1<<endl;
    else
        cout<<min_post<<' '<<min_[0]<<' '<<n-min_[0]<<endl;
    ep;
}