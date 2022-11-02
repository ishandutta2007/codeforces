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

int DP[(1<<17)+7];
int ile[18][200007];

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
        int n,k,ans=0;
        cin>>n>>k;
        string s;
        cin>>s;
        s='#'+s;
        int l=1,r=n,sr;
        while(l<=r)
        {
            sr=(l+r)/2;
            for(int i=0;i<k;i++)
            {
                ile[i][n+1]=inf;
                int last=n+1;
                for(int j=n;j>0;j--)
                {
                    if((s[j]-'a')!=i&&s[j]!='?') last=j;
                    if(last-j>=sr) ile[i][j]=j;
                    else ile[i][j]=ile[i][j+1];
                }
            }
            for(int i=1;i<(1<<k);i++) DP[i]=inf;
            for(int i=0;i<(1<<k);i++)
            {
                if(DP[i]==inf) continue;
                for(int j=0;j<k;j++)
                {
                    if((i&(1<<j))) continue;
                    DP[i|(1<<j)]=min(DP[i|(1<<j)],ile[j][DP[i]+1]+sr-1);
                }
            }
            if(DP[(1<<k)-1]<=n)
            {
                ans=sr;
                l=sr+1;
            }
            else r=sr-1;
        }
        cout<<ans;
    }

    return 0;
}