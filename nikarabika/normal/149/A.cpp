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
    si k;
    cin>>k;
    si a[12];
    rep(i, 12)
        cin>>a[i];
    sort(a, a+12);
    int sum=0;
    if(sum>=k)
    {
        cout<<0<<endl;
        ep;
    }
    for(int i=11; i>=0; i--)
    {
        sum+=a[i];
        if(sum>=k)
        {
            cout<<12-i<<endl;
            ep;
        }
    }
    cout<<-1<<endl;
    ep;
}