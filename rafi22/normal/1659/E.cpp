#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
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

vector<pair<int,int>>G[100007];
int A[100007],B[100007];
int ans[100007];
int id[100007];
bool tak[100007];

void dfs(int v,int c,int i)
{
    id[v]=c;
    for(auto u:G[v])
    {
        if(u.nd%2==0) tak[c]=1;
        if(!id[u.st]&&(u.nd&(1<<i))) dfs(u.st,c,i);
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
        int n,m,a,b,w;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>w;
            G[a].pb({b,w});
            G[b].pb({a,w});
        }
        int q;
        cin>>q;
        for(int i=1;i<=q;i++)
        {
            cin>>A[i]>>B[i];
            ans[i]=2;
        }
        for(int j=0;j<30;j++)
        {
            memset(id,0,sizeof id);
            memset(tak,0,sizeof tak);
            int it=0;
            for(int i=1; i<=n; i++)
            {
                if(id[i]) continue;
                dfs(i,++it,j);
            }
            for(int i=1;i<=q;i++)
            {
                if(id[A[i]]==id[B[i]]) ans[i]=0;
                if(ans[i]==2&&j>0&&tak[id[A[i]]]) ans[i]=1;
            }
        }
        for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
    }

    return 0;
}