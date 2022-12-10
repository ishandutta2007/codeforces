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
    bool x;
    int c=0, res=0;
    bool seeone=false;
    rep(i, n)
    {
        cin>>x;
        if(x)
        {
            if(!seeone)
            {
                seeone=true;
                res++;
            }
            else
            {
                if(c==0)
                    res++;
                else
                    res+=2;
            }
            c=0;
        }
        else
            c++;
    }
    cout<<res<<endl;
    ep;
}