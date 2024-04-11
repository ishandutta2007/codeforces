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

const bool multi=0;

vector<int>G[200007];
int d[200007][2];
bool odw[200007][2];
int mx[200007];

int A[200007];

void bfs(int p,bool b)
{
    deque<int>Q;
    odw[p][b]=1;
    Q.pb(p);
    while(!Q.empty())
    {
        int v=Q[0];
        Q.pop_front();
        for(auto u:G[v])
        {
            if(!odw[u][b])
            {
                odw[u][b]=1;
                d[u][b]=d[v][b]+1;
                Q.pb(u);
            }
        }
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
        int n,m,k,a,b;
        cin>>n>>m>>k;
        for(int i=1;i<=k;i++) cin>>A[i];
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        bfs(1,0);
        bfs(n,1);
        vector<pair<int,int>>vec;
        for(int i=1;i<=k;i++)
        {
            vec.pb({d[A[i]][0]-d[A[i]][1],i});
        }
        sort(vec.begin(),vec.end());
        int ans=0;
        for(int i=k-1;i>=0;i--) mx[i]=max(mx[i+1],d[A[vec[i].nd]][1]);
        int MX=0;
        for(int i=0;i<sz(vec);i++)
        {
            if(i>0) ans=max(ans,MX+1+d[A[vec[i].nd]][1]);
            if(i<k-1) ans=max(ans,mx[i+1]+1+d[A[vec[i].nd]][0]);
            MX=max(MX,d[A[vec[i].nd]][0]);
        }
        ans=min(ans,d[n][0]);
        cout<<ans;
    }

    return 0;
}