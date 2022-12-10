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

typedef unsigned long long int  ull;
typedef long long int           ll;
typedef short int               si;

int main()
{_
    int re=0;
    int n;
    cin>>n;
    rep(i, n)
    {
        int c=0;
        rep(j, 3)
        {
            bool x;
            cin>>x;
            if(x)
                c++;
        }
        if(c>=2)
            re++;
    }
    cout<<re<<endl;
    ep;
}