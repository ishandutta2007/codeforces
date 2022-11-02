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

const int N=300007;

int r[N];
int s[N];

int Find(int v)
{
    if(r[v]==v) return v;
    return Find(r[v]);
}

void Union(int v,int u)
{
    if(s[v]>s[u])
    {
        s[v]+=s[u];
        r[u]=v;
    }
    else
    {
        s[u]+=s[v];
        r[v]=u;
    }
}

vector<int>G[N];
int cnt[N];
int o[N];
void dfs(int v)
{
    for(auto u:G[v])
    {
        if(u==o[v]) continue;
        o[u]=v;
        dfs(u);
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
        int n,m,a,b;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            r[i]=i;
            s[i]=1;
        }
        while(m--)
        {
            cin>>a>>b;
            int x=Find(a),y=Find(b);
            if(x==y) continue;
            Union(x,y);
            G[a].pb(b);
            G[b].pb(a);
        }
        int q;
        cin>>q;
        vector<pair<int,int>>Q(q);
        for(int i=0;i<q;i++)
        {
            cin>>Q[i].st>>Q[i].nd;
            cnt[Q[i].st]++;
            cnt[Q[i].nd]++;
        }
        int ile=0;
        for(int i=1;i<=n;i++) ile+=cnt[i]%2;
        if(ile)
        {
            cout<<"NO"<<endl<<ile/2<<endl;
            return 0;
        }
        cout<<"YES"<<endl;
        for(int i=0;i<q;i++)
        {
            o[Q[i].st]=0;
            dfs(Q[i].st);
            vector<int>res;
            int p=Q[i].nd;
            while(p)
            {
                res.pb(p);
                p=o[p];
            }
            reverse(all(res));
            cout<<sz(res)<<endl;
            for(auto x:res) cout<<x<<" ";
            cout<<endl;
        }
    }

    return 0;
}