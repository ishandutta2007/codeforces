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

vector<int>G[200007];
int pre[200007],post[200007],s[200007],c=1;
int ans[200007];

void dfs(int v,int o)
{
   // cout<<v<<endl;
    s[v]=1;
    pre[v]=c++;
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v);
        s[v]+=s[u];
    }
    post[v]=c++;
}

bool child(int a,int b)
{
    if(pre[b]<=pre[a]&&post[b]>=post[a]) return 1;
    return 0;
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
        int n,a,b,x;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(0,-1);
        a=0,b=1;
        for(auto u:G[0])
        {
            ans[0]+=s[u]*(s[u]-1)/2;
            if(child(b,u)) x=u;
        }
        ans[1]=n*(n-1)/2-ans[0];
        for(int i=2;i<=n;i++)
        {
            //cout<<a<<" "<<b<<endl;
            if(child(b,a)) ans[i]=s[b]*(n-s[x]);
            else ans[i]=s[a]*s[b];
            if(i==n) break;
            bool ok=0;
            if(child(a,i)||child(b,i)) ok=1;
            if(child(i,a)&&!child(i,x))
            {
                a=i;
                ok=1;
            }
            if(child(i,b))
            {
                b=i;
                ok=1;
            }
            if(!ok) break;
        }
        for(int i=1;i<n;i++) ans[i]-=ans[i+1];
        for(int i=0;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
        for(int i=0;i<=n+1;i++)
        {
            ans[i]=0;
            s[i]=0;
            pre[i]=0;
            post[i]=0;
            G[i].clear();
            c=1;
        }
    }

    return 0;
}