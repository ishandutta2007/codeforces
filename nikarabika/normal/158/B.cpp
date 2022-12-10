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
    int a[4];
    a[0]=(a[1]=(a[2]=(a[3]=0)));
    cin>>n;
    rep(i, n)
    {
        int b;
        cin>>b;
        a[b-1]++;
    }
    ull re=a[3]+a[2];
    if(a[2]>=a[0])
        a[0]=0;
    else
        a[0]-=a[2];
    re+=a[1]/2;
    re+=a[0]/4;
    a[1]%=2;
    a[0]%=4;
    re+=(2*a[1]+a[0]+3)/4;
    cout<<re<<endl;
    ep;
}