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

void is_nearly(string s)
{
    int n=0;
    rep(i, s.size())
    {
        if(s[i]==52 || s[i]==55)
            n++;
    }
    if(n==7 || n==4)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

int main()
{_
    string s;
    cin>>s;
    is_nearly(s);
    ep;
}