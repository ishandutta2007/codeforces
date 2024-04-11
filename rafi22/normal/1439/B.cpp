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

const bool multi=1;

vector<int>G[100007];
int deg[100007];
unordered_map<int,bool>is[100007];
bool odw[100007];
int n;

vector<int> check(int k)
{
    memset(odw,0,sizeof odw);
    deque<int>Q;
    for(int i=1;i<=n;i++)
    {
        deg[i]=sz(G[i]);
        if(deg[i]<k)
        {
            odw[i]=1;
            Q.pb(i);
        }
    }
    while(!Q.empty())
    {
        int v=Q[0];
        Q.pop_front();
        for(auto u:G[v])
        {
            deg[u]--;
            if(!odw[u]&&deg[u]<k)
            {
                odw[u]=1;
                Q.pb(u);
            }
        }
    }
    vector<int>res;
    for(int i=1;i<=n;i++) if(!odw[i]) res.pb(i);
    return res;
}

bool is_clique(vector<int> xd,int k)
{
    if(sz(xd)!=k) return 0;
    bool ok=1;
    for(int i=0;i<sz(xd);i++)
    {
        for(int j=i+1;j<sz(xd);j++)
        {
            ok&=is[xd[i]][xd[j]];
        }
    }
    return ok;
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
        int m,k,a,b;
        cin>>n>>m>>k;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
            is[a][b]=1;
            is[b][a]=1;
        }
        vector<int>xd=check(k);
        if(sz(xd)>0)
        {
            cout<<1<<" "<<sz(xd)<<endl;
            for(auto x:xd) cout<<x<<" ";
            cout<<endl;
        }
        else
        {
            xd=check(k-1);
            if(sz(xd)>0)
            {
                deque<int>Q;
                for(auto x:xd) if(deg[x]==k-1) Q.pb(x);
                bool ok=0;
                while(sz(Q)>0)
                {
                    int v=Q[0];
                    odw[v]=1;
                    Q.pop_front();
                    vector<int>c;
                    c.pb(v);
                    for(auto u:G[v])
                    {
                        if(odw[u]) continue;
                        c.pb(u);
                        deg[u]--;
                        if(deg[u]==k-1) Q.pb(u);
                    }
                    if(is_clique(c,k))
                    {
                        cout<<2<<endl;
                        for(auto x:c) cout<<x<<" ";
                        cout<<endl;
                        ok=1;
                        break;
                    }
                }
                if(!ok) cout<<-1<<endl;
            }
            else cout<<-1<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
            is[i].clear();
        }
    }

    return 0;
}