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

const bool multi=1;
vector<int>d[200007];
int DP[200007];
int L[200007];
int R[200007];
int a[200007];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=200000;i++)
    {
        for(int j=1;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                d[i].pb(j);
                d[i].pb(i/j);
            }
        }
    }
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,ans=inf;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            if(L[a[i]]==0) L[a[i]]=i;
            R[a[i]]=i;
        }
        for(int i=1;i<=200000;i++)
        {
            if(L[i])
            {
                DP[i]=L[i]-1;
                for(auto x:d[i])
                {
                    if(L[x]&&x!=i) DP[i]=min(DP[i],DP[x]+L[i]-R[x]-1);
                }
                ans=min(ans,DP[i]+n-R[i]);
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=200000;i++)
        {
            L[i]=0;
            R[i]=0;
        }
    }

    return 0;
}