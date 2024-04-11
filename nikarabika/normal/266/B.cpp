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
    int n, t;
    cin>>n>>t;
    string s;
    cin>>s;
    rep(i, t)
    {
        for(int i=n-2; i>=0; i--)
        {
            if(s[i]=='B' && s[i+1]=='G')
            {
                swap(s[i], s[i+1]);
                i--;
            }
        }
    }
    cout<<s<<endl;
    ep;
}