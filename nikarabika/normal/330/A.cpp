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
    int r, c;
    cin>>r>>c;
    char S[r][c];
    bool is[r][c];
    rep(i, r)
    {
        rep(j, c)
        {
            cin>>S[i][j];
            is[i][j]=false;
        }
    }
    rep(i, r)
    {
        rep(j, c)
        {
            if(S[i][j]=='S')
            {
                is[i][j]=true;
                FOR(k, i+1, r-1)
                {
                    rep(l, c)
                    {
                        if(S[k][l]=='S')
                        {
                            is[k][l]=true;
                            is[i][l]=true;
                            is[k][j]=true;
                        }
                    }
                }
            }
        }
    }
    int re=0;
    rep(i, r)
        rep(j, c)
            if(is[i][j])
                re++;
    cout<<r*c-re<<endl;
    ep;
}