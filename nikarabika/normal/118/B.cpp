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
    bool yy=false;
    for(int i=0; 1;)
    {
        int li=i;
        FOR(j, 1, 2*(n-li))
            cout<<" ";
        int x=0;
        bool xx=false;
        FOR(j, 0, 2*li-1)
        {
            cout<<x<<' ';
            if(!xx)
            {
                if(x==li)
                    xx=true;
                else
                    x++;
            }
            if(xx)
                x--;
        }
        cout<<0<<endl;
        if(!yy)
        {
            if(i==n)
                yy=true;
            else
                i++;
        }
        if(yy)
        {
            i--;
            if(i==-1)
                break;
        }
    }
    ep;
}