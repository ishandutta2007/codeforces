#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,m,u,v,dis[3333][3333],vst[3333],ans[4],len;
vector<pair<int,int> > from[3333],to[3333];
vector<int> adj[3333];
queue<int> q;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        adj[u].pb(v);
    }
    reset(dis,-1);
    For(i,1,1+n)
    {
        reset(vst,-1);
        q.push(i);
        vst[i]=0;
        while(!q.empty())
        {
            u=q.front();q.pop();
            for(int nex:adj[u]) if(vst[nex]==-1)
            {
                vst[nex]=vst[u]+1;
                dis[i][nex]=vst[nex];
                from[i].pb({vst[nex],nex});
                to[nex].pb({vst[nex],i});
                q.push(nex);
            }
        }
    }
    For(i,1,1+n) sort(to[i].begin(),to[i].end());
    //for(auto i:from[1]) cout<<i.second<<' '<<i.first<<endl;
    len=0;
    For(b,1,1+n) For(c,1,1+n) if(b!=c&&dis[b][c]!=-1)
    {
        For(i,max(0,(int)to[b].size()-3),to[b].size()) For(j,max(0,(int)from[c].size()-3),from[c].size())
        {
            int a = to[b][i].second;
            int d = from[c][j].second;
            if(a!=d&&a!=c&&b!=d&&len<dis[a][b]+dis[b][c]+dis[c][d])
            {
                len = dis[a][b]+dis[b][c]+dis[c][d];
                ans[0]=a;ans[1]=b;ans[2]=c;ans[3]=d;
            }
        }
    }
    For(i,0,4) cout<<ans[i]<<' ';
}