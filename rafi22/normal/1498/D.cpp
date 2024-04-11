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

int DP[100007];
int need[100007];

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
        int n,m;
        cin>>n>>m;
        memset(DP,-1,sizeof DP);
        DP[0]=0;
        for(int i=1;i<=n;i++)
        {
            int t,x,y;
            cin>>t>>x>>y;
            if(t==1)
            {
                for(int j=0;j<=m;j++)
                {
                    need[j]=-1;
                    if(DP[j]>=0) need[j]=0;
                    else if((j-x/100000-(x%100000!=0))>=0&&need[j-x/100000-(x%100000!=0)]>=0) need[j]=need[j-x/100000-(x%100000!=0)]+1;
                }
                for(int j=1;j<=m;j++) if(need[j]>0&&need[j]<=y) DP[j]=i;
            }
            else
            {
                for(int j=0; j<=m; j++)
                {
                    need[j]=-1;
                    if(DP[j]>=0) need[j]=0;
                    else
                    {
                        int l=0,r=j-1,sr,L=-1;
                        while(l<=r)
                        {
                            sr=(l+r)/2;
                            if(sr*x/100000+min(1LL,sr*x%100000)==j)
                            {
                                L=sr;
                                break;
                            }
                            else if(sr*x/100000+min(1LL,sr*x%100000)<j) l=sr+1;
                            else r=sr-1;
                        }
                        if(L!=-1&&need[L]>=0) need[j]=need[L]+1;
                    }
                }
                for(int j=1;j<=m;j++) if(need[j]>0&&need[j]<=y) DP[j]=i;
            }
        }
        for(int j=1;j<=m;j++) cout<<DP[j]<<" ";
    }

    return 0;
}