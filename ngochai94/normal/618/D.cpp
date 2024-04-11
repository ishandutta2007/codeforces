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

long long n,x,y,u,v,ans,cur,vst[200005],dp[2][200005];
vector<long long> adj[200005],vec;
queue<long long> Q;
bool flag;

void bfs(long long st)
{
    reset(vst,-1);
    while(!Q.empty()) Q.pop();
    Q.push(st);
    vst[st]=0;
    vec.pb(st);
    while(!Q.empty())
    {
        cur=Q.front();Q.pop();

        for(long long nex:adj[cur])
        {
            if(vst[nex]==-1)
            {
                vst[nex]=1+vst[cur];
                Q.push(nex);
                vec.pb(nex);
            }
        }
    }
}


int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>x>>y;
    if(n==2)
    {
        cout<<x;return 0;
    }
    For(i,1,n)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(y<=x)
    {
        ans=0;
        For(i,1,n+1) if(adj[i].size()==n-1) ans++;
        //cout<<ans<<endl;
        cout<<x*ans+y*(n-1-ans);return 0;
    }

    bfs(1);
    ans=0;
    for(int i=n-1;i>=0;i--)
    {
        cur=vec[i];
        dp[0][cur]=dp[1][cur]=0;
        flag=false;
        for(long long nex:adj[cur]) if(vst[nex]>vst[cur])
        {
            dp[1][cur]+=dp[1][nex];
            if(dp[0][nex])
            {
                if(dp[0][cur]<2) dp[0][cur]++;
                else dp[1][cur]++;
            }
        }
        if(dp[0][cur]==0) dp[0][cur]=1;
        dp[1][cur]+=dp[0][cur]/2;
        dp[0][cur]=dp[0][cur]%2;

        //cout<<cur<<' '<<dp[0][cur]<<' '<<dp[1][cur]<<endl;
    }
    ans=dp[1][1]+dp[0][1];
    //cout<<dp[0][1]<<' '<<dp[1][1]<<endl;
    //cout<<ans<<endl;
    cout<<x*(n-ans)+y*(ans-1);
}