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
    int n, m;
    cin>>n>>m;
    int max_i=-1, max_j=-1;
    int min_j=-1, min_i=-1;
    char s[n][m];
    rep(i, n)
    {
        rep(j, m)
        {
            char x;
            cin>>x;
            s[i][j]=x;
            if(x=='*')
            {
                if(min_i==-1)
                {
                    min_i=i;
                    max_i=i;
                    min_j=j;
                    max_j=j;
                }
                if(i<min_i)
                    min_i=i;
                else if(i>=max_i)
                    max_i=i;
                if(j<min_j)
                    min_j=j;
                else if(j>=max_j)
                    max_j=j;
            }
        }
    }
    FOR(i, min_i, max_i)
    {
        FOR(j, min_j, max_j)
        {
            cout<<s[i][j];
        }
        cendl;
    }
    ep;
}