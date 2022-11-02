#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int tab[300007];
int DP[300007][2];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>tab[i];
        DP[1][1]=tab[1];
        for(int i=2;i<=n;i++)
        {
            DP[i][1]=DP[i-1][1];
            DP[i][1]=max(DP[i][1],DP[i-1][0]+tab[i]);
            DP[i][0]=DP[i-1][0];
            DP[i][0]=max(DP[i][0],DP[i-1][1]-tab[i]);
        }
        cout<<DP[n][1]<<endl;
    }

    return 0;
}