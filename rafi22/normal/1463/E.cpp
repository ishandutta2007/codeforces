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

void gg()
{
    cout<<0;
    exit(0);
}
int p[300007];
int nx[300007];
int pre[300007];
vector<int> block[300007];
int id[300007];
int pos[300007];
vector<int>G[300007];
int ile[300007];
deque<int>Q;
vector<int>ans;

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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>p[i];
        bool no=0;
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            if(nx[x]||pre[y]) no=1;
            nx[x]=y;
            pre[y]=x;
        }
        if(no) gg();
        for(int i=1;i<=n;i++) if(nx[nx[i]]==i) gg();
        int it=0;
        for(int i=1;i<=n;i++)
        {
            if(!id[i]&&!pre[i])
            {
                it++;
                int v=i,cnt=0;
                while(v!=0)
                {
                    block[it].pb(v);
                    id[v]=it;
                    pos[v]=++cnt;
                    v=nx[v];
                }
            }
        }
        for(int i=1;i<=it;i++)
        {
            for(auto x:block[i])
            {
                if(p[x])
                {
                    if(id[p[x]]!=i)
                    {
                        G[id[p[x]]].pb(i);
                       // cout<<id[p[x]]<<" "<<i<<endl;
                        ile[i]++;
                    }
                    else if(pos[p[x]]>pos[x]) gg();
                }
            }
        }
        for(int i=1;i<=it;i++) if(ile[i]==0) Q.pb(i);
        while(!Q.empty())
        {
            int v=Q[0];
            Q.pop_front();
            ans.pb(v);
            for(auto u:G[v])
            {
                ile[u]--;
                if(ile[u]==0) Q.pb(u);
            }
        }
        if(sz(ans)<it) gg();
        for(auto x:ans)
        {
            for(auto y:block[x]) cout<<y<<" ";
        }

    }

    return 0;
}