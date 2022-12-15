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

int n,m,u,v,vst[100005];
vector<int> adj[100005];
queue<int> q;


int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    For(i,0,m)
    {
        cin>>u>>v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans=0;
    For(i,0,n) if(!vst[i])
    {
        vst[i]=1;
        q.push(i);
        int cnt=0,deg=0;
        while(!q.empty())
        {
            u=q.front();q.pop();
            cnt++;deg+=adj[u].size();
            for(int nex:adj[u]) if(!vst[nex])
            {
                vst[nex]=1;
                q.push(nex);
            }
        }
        if(cnt-1==deg/2) ans++;
    }
    cout<<ans;
}