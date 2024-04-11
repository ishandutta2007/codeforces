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
    int n;
    cin>>n;
    int a[2]={0, 0};
    rep(i, n)
    {
        int x;
        cin>>x;
        a[x%2]++;
    }
    if(a[1]%2)
        cout<<a[1];
    else
        cout<<a[0];
    cendl;
    ep;
}