#include <bits/stdc++.h>

using namespace std;

#define     _               std::ios_base::Init i; std::ios_base::sync_with_stdio(false); std::cin.tie(0);
#define     All(a)          a.begin(), a.end()
#define     FOR(i, s, e)    for(ull i=s; i<=e; i++)
#define     rep(i, t)       for(ull i=0; i<t; i++)
#define     sp              system("pause")
#define     ep              return 0
#define     cendl           cout<<endl
#define     pb              push_back
#define     pob             pop_back
#define     mp              make_pair
#define     L               first
#define     R               second

typedef unsigned long long int  ull;
typedef long long int           ll;
typedef short int               si;

ull a[100001];
ull dp[100001];

int main()
{_
    int n;
    cin>>n;
    int sz=0;
    rep(i, n)
    {
        int t;
        cin>>t;
        a[t]++;
        if(t>sz)
            sz=t;
    }
    dp[0]=0;
    dp[1]=a[1];
    FOR(i, 2, sz+1)
        dp[i]=max(dp[i-1], dp[i-2]+(i*a[i]));
    ull max_=0;
    rep(i, sz+1)
        if(dp[i]>max_)
            max_=dp[i];
    cout<<max_<<endl;
    ep;
}