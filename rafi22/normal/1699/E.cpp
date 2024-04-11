#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

const int M=5000007;

bool is[M];
int DP[M];
int cnt[M];

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
        int n,m,x,mx=1;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            is[x]=1;
        }
        for(int i=2;i<=m;i++) DP[i]=0;
        DP[1]=1;
        for(int i=1;i<=m;i++) if(is[i]) cnt[DP[i]]++;
        int mn=0,ans=inf;
        for(int i=1;i<=m;i++)
        {
            while(cnt[mn]==0) mn++;
            if(i>1)
            {
                for(int j=i;j<=m;j+=i)
                {
                    if(is[j]) cnt[DP[j]]--;
                    if(j==i) DP[j]=j;
                    else DP[j]=max(DP[j],DP[j/i]);
                    if(is[j]) cnt[DP[j]]++;
                }
            }
            while(cnt[mn]==0) mn++;
            if(mn!=0) ans=min(ans,i-mn);
        }
        cout<<ans<<endl;
        for(int i=0;i<=m;i++)
        {
            is[i]=0;
            cnt[i]=0;
        }
    }

    return 0;
}