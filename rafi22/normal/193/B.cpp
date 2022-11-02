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

const bool multi=0;

int n,u,r,ans=-inf;
vector<int>act;
int a[37],b[37],k[37],p[37],rp[37];
int na[37];

void bt(int i,bool last)
{
    if((u-i)%2==0)
    {
        int sum=0;
        for(int i=1;i<=n;i++) sum+=a[i]*k[i];
        ans=max(ans,sum);
    }
    if(i==u) return;
    if(!last)
    {
        for(int i=1;i<=n;i++) a[i]^=b[i];
        bt(i+1,1);
        for(int i=1;i<=n;i++) a[i]^=b[i];
    }
    for(int i=1;i<=n;i++) na[i]=a[p[i]]+r;
    for(int i=1;i<=n;i++) a[i]=na[i];
    bt(i+1,0);
    for(int i=1;i<=n;i++) na[i]=a[rp[i]]-r;
    for(int i=1;i<=n;i++) a[i]=na[i];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>u>>r;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>k[i];
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        rp[p[i]]=i;
    }
    bt(0,0);
    cout<<ans<<endl;

    return 0;
}