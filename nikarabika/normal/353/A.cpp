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

bool is(int);

int main()
{_
    int n;
    cin>>n;
    pair <int, int> a[n];
    int up=0, low=0;
    rep(i, n)
    {
        cin>>a[i].first>>a[i].second;
        up+=a[i].first;
        low+=a[i].second;
    }
    //rep(i, n)
    if(up%2==1 && low%2==1)
    {
        bool changed=false;
        rep(i, n)
        {
            if(a[i].first%2==1 && a[i].second%2==0 || a[i].first%2==0 && a[i].second%2==1)
            {
                cout<<1<<endl;
                changed=true;
                break;
            }
        }
        if(!changed)
            cout<<-1<<endl;
    }
    else if(up%2==0 && low%2==0)
        cout<<0<<endl;
    else
        cout<<-1<<endl;
    ep;
}