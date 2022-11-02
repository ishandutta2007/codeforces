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

vector<int>G[1000007];
vector<int>RG[1000007];
vector<int>post;
bool odw[1000007];
int scc[1000007];
int ile[1000007];

void dfs(int v)
{
    odw[v]=1;
    for(auto u:G[v])
    {
        if(odw[u]) continue;
        dfs(u);
    }
    post.pb(v);
}
void dfs1(int v,int c)
{
    scc[v]=c;
    for(auto u:RG[v])
    {
        if(!scc[u]) dfs1(u,c);
        else if(scc[u]!=c) ile[scc[u]]++;
    }
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
        int n,m,a,b;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            RG[b].pb(a);
        }
        for(int i=1;i<=n;i++) if(!odw[i]) dfs(i);
        reverse(post.begin(),post.end());
        int c=1;
        for(auto i:post) if(!scc[i]) {dfs1(i,c);c++;}
        int p=-1;
        bool tak=0;
        for(int i=2;i<=n;i++) if(scc[i]!=scc[i-1]) tak=1;
        for(int i=1;i<c;i++) if(ile[i]==0) p=i;
        vector<int>ans1,ans2;
        if(tak)
        {
            for(int i=1;i<=n;i++)
            {
                if(scc[i]==p) ans1.pb(i);
                else ans2.pb(i);
            }
            cout<<"Yes"<<endl;
            cout<<sz(ans1)<<" "<<sz(ans2)<<endl;
            for(auto x:ans1) cout<<x<<" ";
            cout<<endl;
            for(auto x:ans2) cout<<x<<" ";
            cout<<endl;
        }
        else cout<<"No"<<endl;
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
            RG[i].clear();
            odw[i]=0;
            scc[i]=0;
            ile[i]=0;
            post.clear();
        }
    }

    return 0;
}