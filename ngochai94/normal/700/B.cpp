#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-8
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

long long n,k,deg[200005],val,ans,mak[200005],dp[200005],par[200005],u,v;
vector<long long> adj[200005], uni;
queue<int> q;

void f(long long x) {
    dp[x]=0;
    for(int i:adj[x]) if(i!=par[x]) {
        if(dp[i]==-1) f(i);
    }
    if(mak[x]) dp[x]++;
    dp[par[x]] += dp[x];
}

int main( ){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>k;
    For(i,0,2*k) {
        cin>>val;
        val--;
        uni.pb(val);
        mak[val]=1;
    }
    For(i,1,n) {
        cin>>u>>v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    reset(deg,-1);
    deg[0]=0;
    q.push(0);
    par[0]=-1;
    while(!q.empty()) {
        u = q.front(); q.pop();
        // cout<<u<<' '<<deg[u]<<endl;
        for(int nex:adj[u]) if(deg[nex]==-1) {
            deg[nex] = 1 + deg[u];
            par[nex]=u;
            q.push(nex);
        }
    }
    for(int i:uni) ans+=deg[i];
    // cout<<ans<<endl;
    reset(dp,-1);
    f(0);
    q.push(0);
    while(!q.empty()) {
        u=q.front(); q.pop();
        for(int nex:adj[u]) if(nex!=par[u] && dp[nex] > k) {
            ans-=2*(dp[nex]-k);
            q.push(nex);
            break;
        } 
    }
    cout<<ans;
}