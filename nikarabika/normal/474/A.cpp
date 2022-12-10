#include <bits/stdc++.h>

using namespace std;

#define     _               std::ios_base::Init i; std::ios_base::sync_with_stdio(false); std::cin.tie(0);
#define     FOR(i, s, e)    for(ll i=s; i<=e; i++)
#define     rep(i, t)       for(ll i=0; i<t; i++)
#define     pb              push_back
#define     mp              make_pair
#define     p1              first
#define     p2              second

typedef unsigned long long int  ull;
typedef long long int           ll;
typedef short int               si;

int main()
{_
    char a[3][12]={{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']'}, {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', ' '}, {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', ' '}};
    char st;
    cin>>st;
    string s;
    cin>>s;
    rep(i, s.size())
    {
        rep(j, 3)
        {
            rep(k, 12)
            {
                if(s[i]==a[j][k])
                {
                    if(st=='L')
                        cout<<a[j][k+1];
                    else
                        cout<<a[j][k-1];
                }
            }
        }
    }
    cout<<endl;
    return 0;
}