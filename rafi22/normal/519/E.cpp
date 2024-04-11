#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ll long long
ll mod=1000000007;
int inf=1000000007;
ll infl=1000000000000000007;

const int N=100007;

vector<int>G[N];
vector<int>G1[N];
int skok[N][17];
int s[N],d[N];
int pre[N],post[N],c=0;

void dfs(int v,int o)
{
    s[v]=1;
    skok[v][0]=o;
    pre[v]=++c;
    for(int i=1;i<17;i++) skok[v][i]=skok[skok[v][i-1]][i-1];
    for(auto u:G[v])
    {
        if(u==o) continue;
        G1[v].pb(u);
        d[u]=d[v]+1;
        dfs(u,v);
        s[v]+=s[u];
    }
    post[v]=++c;
}
bool anc(int u,int v)
{
    return pre[u]<=pre[v]&&post[u]>=post[v];
}
int lca(int u,int v)
{
    if(anc(u,v)) return u;
    for(int i=16;i>=0;i--) if(!anc(skok[u][i],v)) u=skok[u][i];
    return skok[u][0];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a,b,m;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(1,1);
    cin>>m;
    while(m--)
    {
        cin>>a>>b;
        if(a==b)
        {
            cout<<n<<endl;
            continue;
        }
        int u=lca(a,b);
        int l=d[a]+d[b]-2*d[u];
        if(l%2==1) cout<<0<<endl;
        else
        {
            l/=2;
            int x;
            if(d[a]>d[b]) x=a;
            else x=b;
            for(int i=16;i>=0;i--)
            {
                if((1<<i)<=l)
                {
                    l-=(1<<i);
                    x=skok[x][i];
                }
            }
            int ans=n,k,sr,r;
            l=0,r=sz(G1[x])-1,sr,k=-1;
            while(l<=r)
            {
                sr=(l+r)/2;
                int c=G1[x][sr];
                if(pre[a]>post[c]) l=sr+1;
                else if(anc(c,a))
                {
                    k=c;
                    break;
                }
                else r=sr-1;
            }
            if(k==-1) ans-=n-s[x];
            else ans-=s[k];
           // cout<<a<<" "<<k<<endl;
            l=0,r=sz(G1[x])-1,sr,k=-1;
            while(l<=r)
            {
                sr=(l+r)/2;
                int c=G1[x][sr];
                if(pre[b]>post[c]) l=sr+1;
                else if(anc(c,b))
                {
                    k=c;
                    break;
                }
                else r=sr-1;
            }
            if(k==-1) ans-=n-s[x];
            else ans-=s[k];
            cout<<ans<<endl;
        }
    }

    return 0;
}