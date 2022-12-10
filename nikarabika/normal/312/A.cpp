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
    int n;
    cin>>n;
    getline(cin, s);
    rep(i, n)
    {
        getline(cin, s);
        if(s.length()<5)
        {
            cout<<"OMG>.< I don't know!"<<endl;
            continue;
        }
        bool a=false, b=false;
        if("miao."==s.substr(0, 5))
            a=true;
        if("lala."==s.substr(s.length()-5, s.length()))
            b=true;
        if(a&&b || !a&&!b)
            cout<<"OMG>.< I don't know!"<<endl;
        else if(b)
            cout<<"Freda's"<<endl;
        else
            cout<<"Rainbow's"<<endl;
    }
    ep;
}