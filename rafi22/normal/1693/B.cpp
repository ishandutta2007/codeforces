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

const int N=200007;

vector<int>G[N];
int l[N],r[N];
int a[N];
int ans;

void dfs(int v)
{
    int sum=0;
    for(auto u:G[v])
    {
        dfs(u);
        sum+=a[u];
    }
    if(sum<l[v])
    {
        ans++;
        a[v]=r[v];
    }
    else a[v]=min(r[v],sum);
}

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
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=2;i<=n;i++)
        {
            int p;
            cin>>p;
            G[p].pb(i);
        }
        for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
        ans=0;
        dfs(1);
        cout<<ans<<endl;
    }

    return 0;
}