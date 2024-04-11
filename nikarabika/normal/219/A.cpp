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
    int k;
    vector <pair<char, int> > a;
    vector <int> b;
    string s;
    cin>>k>>s;
    rep(i, s.size())
    {
        bool x=true;
        rep(j, a.size())
        {
            if(a[j].first==s[i])
            {
                a[j].second++;
                x=false;
            }
        }
        if(x)
            a.pb(make_pair(s[i], 1));
    }
    rep(i, a.size())
    {
        if(a[i].second%k!=0)
        {
            cout<<-1<<endl;
            ep;
        }
        else
            b.pb(a[i].second/k);
    }
    rep(i, k)
        rep(j, b.size())
            rep(k, b[j])
                cout<<a[j].first;
    ep;
}