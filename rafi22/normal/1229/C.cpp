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

const int N=100007;

vector<int>G[N];
vector<int>BG[N];
set<int>Q[N];
int in[N],out[N];
int t[N];
bool big[N];
ll ans;
void usun(int u,int v)
{
  //  cout<<"U "<<u<<" "<<v<<endl;
    ans-=in[v]*out[v];
    ans-=in[u]*out[u];
    if(t[u]<t[v])
    {
        in[v]--;
        out[u]--;
    }
    if(t[u]>t[v])
    {
        in[u]--;
        out[v]--;
    }
    ans+=in[v]*out[v];
    ans+=in[u]*out[u];
}
void dodaj(int u,int v)
{
 //   cout<<"D "<<u<<" "<<v<<endl;
    ans-=in[v]*out[v];
    ans-=in[u]*out[u];
    if(t[u]<t[v])
    {
        in[v]++;
        out[u]++;
    }
    if(t[u]>t[v])
    {
        in[u]++;
        out[v]++;
    }
    ans+=in[v]*out[v];
    ans+=in[u]*out[u];
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
        int S=sqrt(n);
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        for(int i=1;i<=n;i++) if(sz(G[i])>S) big[i]=1;
        for(int i=1;i<=n;i++)
        {
            t[i]=i;
            for(auto u:G[i])
            {
                if(u<i)
                {
                    dodaj(i,u);
                    if(big[u]&&!big[i]) Q[u].insert(i);
                }
                if(big[u]) BG[i].pb(u);
            }
        }
        cout<<ans<<endl;
        int q;
        cin>>q;
        for(int i=1;i<=q;i++)
        {
            int v;
            cin>>v;
            if(!big[v])
            {
                for(auto u:G[v]) usun(v,u);
                t[v]=i+n;
                for(auto u:G[v]) dodaj(v,u);
                for(auto u:BG[v]) Q[u].insert(v);
            }
            else
            {
                for(auto u:BG[v]) usun(v,u);
                for(auto u:Q[v]) usun(v,u);
                t[v]=i+n;
                for(auto u:BG[v]) dodaj(v,u);
                for(auto u:Q[v]) dodaj(v,u);
                Q[v].clear();
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}