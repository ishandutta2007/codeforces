#include <bits/stdc++.h>

//#define int long long
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

vector<int>G[2500007];
vector<int>RG[2500007];
bool odw[2500007];
int scc[2500007];
vector<int>post;

void dfs(int v)
{
    odw[v]=1;
    for(auto u:RG[v]) if(!odw[u]) dfs(u);
    post.pb(v);
}
void dfsS(int v,int k)
{
    scc[v]=k;
    for(auto u:G[v]) if(scc[u]==0) dfsS(u,k);
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
        int n,p,M,m,a,b;
        cin>>n>>p>>M>>m;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            G[2*a+1].pb(2*b);
            G[2*b+1].pb(2*a);
        }
        for(int i=p+1;i<p+M;i++)
        {
            G[2*i].pb(2*(i+M+1)+1);
            G[2*(i+M+1)+1].pb(2*i);
            G[2*(i+M+1)].pb(2*i+1);
            G[2*i+1].pb(2*(i+M+1));
            G[2*i].pb(2*(i+1));
            G[2*(i+1)+1].pb(2*i+1);
            G[2*(i+M)+1].pb(2*(i+M+1)+1);
            G[2*(i+M+1)].pb(2*(i+M));
        }
        G[2*(p+M)+1].pb(2*(p+M));
        G[2*(p+M+1)+1].pb(2*(p+M+1));
        for(int i=1;i<=p;i++)
        {
            cin>>a>>b;
            if(a!=1)
            {
                G[2*i].pb(2*(p+a-1)+1);
                G[2*(p+a-1)].pb(2*i+1);
            }
            if(b!=M)
            {
                G[2*i].pb(2*(p+M+b+1)+1);
                G[2*(p+M+b+1)].pb(2*i+1);
            }
        }
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            G[2*a].pb(2*b+1);
            G[2*b].pb(2*a+1);
        }
        for(int i=2;i<=2*(p+M*2)+1;i++) for(auto x:G[i]) RG[x].pb(i);
        for(int i=2;i<=2*(p+M*2)+1;i++) if(!odw[i]) dfs(i);
        reverse(post.begin(),post.end());
        int it=1;
        for(auto x:post) if(!scc[x]) dfsS(x,it++);
        vector<int> res;
        for(int i=1;i<=p+2*M;i++)
        {
           // cout<<scc[2*i]<<" "<<scc[2*i+1]<<endl;
            if(scc[2*i]==scc[2*i+1])
            {
                cout<<-1;
                return 0;
            }
        }
        int k=-1;
        for(int i=1;i<=p;i++) if(scc[2*i]<scc[2*i+1]) res.pb(i);
        for(int i=p+1;i<=p+M;i++) if(scc[2*i]<scc[2*i+1]&&scc[2*(i+M)]<scc[2*(i+M)+1]) k=i-p;
        cout<<sz(res)<<" "<<k<<endl;
        for(auto x:res) cout<<x<<" ";
    }

    return 0;
}