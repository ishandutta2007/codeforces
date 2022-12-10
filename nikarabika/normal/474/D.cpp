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

#define D 1000000007
ll dp[100001];
ll s[100001];

ll DP(int i)
{
    if(i<0)
        return 0;
    return dp[i];
}

int main()
{_
    int n, k;
    cin>>n>>k;
    dp[0]=1;
    FOR(i, 1, 100000)
    {
        dp[i]=(DP(i-1)+DP(i-k))%D;
        s[i]=(s[i-1]+dp[i])%D;
    }
    rep(i, n)
    {
        int a, b;
        cin>>a>>b;
        cout<<(((s[b]-s[a-1])%D)+D)%D<<endl;
    }
    return 0;
}