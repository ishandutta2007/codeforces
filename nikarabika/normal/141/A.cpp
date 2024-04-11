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

map <char, int> a;
map <char, int> r;

int main()
{_
    string s[3];
    cin>>s[0];
    rep(i, s[0].size())
        a[s[0][i]]++;
    cin>>s[1];
    rep(i, s[1].size())
        a[s[1][i]]++;
    cin>>s[2];
    rep(i, s[2].size())
        r[s[2][i]]++;

    if(s[0].size()+s[1].size()!=s[2].size())
    {
        cout<<"NO"<<endl;
        ep;
    }

    rep(i, s[2].size())
    {
        if(a[s[2][i]]!=r[s[2][i]])
        {
            cout<<"NO"<<endl;
            ep;
        }
    }
    cout<<"YES"<<endl;
    ep;
}