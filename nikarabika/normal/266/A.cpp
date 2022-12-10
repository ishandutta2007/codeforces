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
    int n;
    ull re=0;
    cin>>n;
    vector <int> a;
    rep(i, n)
    {
        char x;
        cin>>x;
        if(x=='R')
            a.pb(0);
        else if(x=='G')
            a.pb(1);
        else
            a.pb(2);
    }
    a.pb(-1);
    FOR(i, 1, a.size()-1)
    {
        if(a[i]==a[i-1])
        {
            a.erase(a.begin()+i);
            re++;
            i--;
        }
    }
    cout<<re<<endl;
    ep;
}