#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int N=200007;

vector<int>G[N];
int o[N];
int DP[N];
int ans[N];
vector<pair<int,int>>Q[N];
bool is[N];
vector<int>add[N];
int A[N],B[N];

void dfs(int v,int k)
{
    DP[v]=0;
    for(auto u:G[v])
    {
        if(u==o[v]) continue;
        o[u]=v;
        dfs(u,k);
        DP[v]+=max(1LL,DP[u]-k);
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
        int n,a,b;
        cin>>n;
        for(int i=1;i<n;i++)
        {
          //  a=i+1;
           // b=rand()%i+1;
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        int q;
        cin>>q;
        for(int i=1;i<=q;i++)
        {
            int v,k;
            cin>>v>>k;
            Q[k].pb({v,i});
        }
        for(int i=0;i<=50;i++)
        {
            dfs(1,i);
            for(auto v:Q[i]) ans[v.nd]=DP[v.st];
        }
        A[1]=sz(G[1]);
        for(int i=2;i<=n;i++) A[i]=sz(G[i])-1;
        for(int i=1;i<=n;i++)
        {
            int c=(A[i]-1)/(B[i]+1);
            if(c>=0) add[c].pb(i);
        }
        for(int i=200000;i>50;i--)
        {
            for(int j=0;j<sz(add[i]);j++)
            {
                int x=add[i][j];
                if(is[x]) continue;
                int v=x;
                is[v]=1;
                int a=A[v],b=B[v];
                while(v!=1)
                {
                    A[o[v]]+=a-1;
                    B[o[v]]+=b+1;
                    if(!is[o[v]])
                    {
                        int c=(A[o[v]]-1)/(B[o[v]]+1);
                        if(c>=0) add[c].pb(o[v]);
                        break;
                    }
                    v=o[v];
                }
            }
            for(auto v:Q[i]) ans[v.nd]=A[v.st]-i*B[v.st];
        }
        for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
    }

    return 0;
}