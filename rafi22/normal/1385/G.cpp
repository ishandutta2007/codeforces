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

const bool multi=1;
vector<int>G[400007];
int pos[400007];
int cnt[400007];
bool odw[400007];
vector<int>vec;
bool ans[400007];
void dfs(int v)
{
    vec.pb(v);
    odw[v]=1;
    for(auto u:G[v])
    {
        if(!odw[u]) dfs(u);
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
        int n,a;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            if(pos[a])
            {
                G[2*i+1].pb(2*pos[a]);
                G[2*pos[a]].pb(2*i+1);
                G[2*pos[a]+1].pb(2*i);
                G[2*i].pb(2*pos[a]+1);
            }
            else pos[a]=i;
            cnt[a]++;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            if(pos[a])
            {
                if(pos[a]>n)
                {
                    pos[a]-=n;
                    G[2*i+1].pb(2*pos[a]);
                    G[2*pos[a]].pb(2*i+1);
                    G[2*pos[a]+1].pb(2*i);
                    G[2*i].pb(2*pos[a]+1);
                }
                else
                {
                    G[2*i+1].pb(2*pos[a]+1);
                    G[2*pos[a]+1].pb(2*i+1);
                    G[2*i].pb(2*pos[a]);
                    G[2*pos[a]].pb(2*i);
                }
            }
            else pos[a]=i+n;
            cnt[a]++;
        }
        bool zle=0;
        for(int i=1;i<=n;i++) if(cnt[i]!=2) zle=1;
        vector<int>res;
        for(int i=1;i<=2*n;i++)
        {
            if(!odw[i])
            {
                vec.clear();
                dfs(i);
                int c1=0,c2=0;
                for(auto x:vec)
                {
                    if(x&1) c2++;
                    else c1++;
                }
                if(sz(vec)==1) continue;
                if(c2>c1)
                {
                    for(auto x:vec)
                    {
                        if(!ans[x]&&!ans[x^1]) ans[x]=1;
                    }
                }
                else
                {
                    for(auto x:vec)
                    {
                        if(!ans[x]&&!ans[x^1]) ans[x^1]=1;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++) if(ans[2*i]) res.pb(i);
        if(zle)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<sz(res)<<endl;
            for(auto x:res)
            {
                if(x==-1) return 2137;
                cout<<x<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<=2*n+1;i++)
        {
            G[i].clear();
            odw[i]=0;
            cnt[i]=0;
            pos[i]=0;
            ans[i]=0;
        }
    }

    return 0;
}