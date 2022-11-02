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

int a[500007];
int cnt[500007];
int act[500007];
int p[500007];
int k[500007];
int DP[500007];

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
        int n,ans=inf;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            cnt[a[i]]++;
            if(p[a[i]]==0) p[a[i]]=i;
            k[a[i]]=i;
        }
        DP[0]=n;
        for(int i=1;i<=n;i++)
        {
            ans=min(ans,DP[i-1]-(cnt[a[i]]-act[a[i]]));
            act[a[i]]++;
            if(i==k[a[i]]) DP[i]=min(DP[i-1],DP[p[a[i]]-1]-cnt[a[i]]);
            else DP[i]=DP[i-1];
        }
        ans=min(ans,DP[n]);
        cout<<ans;
    }

    return 0;
}