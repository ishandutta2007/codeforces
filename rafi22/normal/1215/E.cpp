#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int a[400007];
int cnt[21][21];
int ile[21];
int DP[(1<<20)+7];
int cost[(1<<20)+7][21];
int lg[(1<<20)+7];

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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            ile[a[i]]++;
            for(int j=1;j<=20;j++) cnt[a[i]][j]+=ile[j];
        }
        for(int i=1;i<=20;i++) lg[(1<<(i-1))]=i;
        for(int j=1;j<=20;j++)
        {
            for(int i=1;i<=20;i++) if(i!=j) cost[0][j]+=cnt[j][i];
            for(int i=1;i<(1<<20);i++)
            {
                cost[i][j]=cost[i-(i&-i)][j]-(lg[(i&-i)]!=j)*cnt[j][lg[(i&-i)]];
            }
        }
        for(int i=1;i<(1<<20);i++) DP[i]=inf;
        for(int i=0;i<(1<<20);i++)
        {
            for(int j=1;j<=20;j++)
            {
                if((i&((1<<(j-1))))==0) DP[i|(1<<(j-1))]=min(DP[i|(1<<(j-1))],DP[i]+cost[i][j]);
            }
        }
        cout<<DP[(1<<20)-1];
    }

    return 0;
}