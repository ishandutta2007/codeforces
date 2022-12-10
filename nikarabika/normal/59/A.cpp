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
    string s;
    cin>>s;
    int upper=0;
    rep(i, s.size())
        if(s[i]<97)
            upper++;
    int lower=s.size()-upper;
    if(upper>lower)
    {
        //cout<<1<<endl;
        rep(i, s.size())
            if(int(s[i])>=97)
                s[i]-=32;
    }
    else
    {
        //cout<<2<<endl;
        rep(i, s.size())
            if(int(s[i])<97)
                s[i]+=32;
    }
    cout<<s<<endl;
    ep;
}