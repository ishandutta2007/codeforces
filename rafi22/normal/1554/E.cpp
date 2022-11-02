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

vector<int>G[100007];
bool out[100007];
int ile[100007];

bool dfs(int v,int o,int k)
{
    int deg=0;
    bool ok=1;
    for(auto u:G[v])
    {
        if(u==o) continue;
        ok&=dfs(u,v,k);
        deg+=out[u];
    }
    if(deg%k==0) out[v]=1;
    else if(o!=-1&&(deg+1)%k==0) out[v]=0;
    else return 0;
    return ok;
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
        mod=mod1;
        int n,a,b;
        cin>>n;
        ile[1]=1;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
            ile[1]=ile[1]*2%mod;
        }
        for(int i=2;i<=n-1;i++)
        {
            if((n-1)%i!=0) continue;
            //cout<<i<<endl;
            ile[i]=dfs(1,-1,i);
        }
        for(int i=n;i>0;i--)
        {
            for(int j=2*i;j<=n;j+=i)
            {
                ile[i]-=ile[j];
                if(ile[i]<0) ile[i]+=mod;
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<ile[i]<<" ";
            ile[i]=0;
            G[i].clear();
        }
        cout<<endl;
    }

    return 0;
}