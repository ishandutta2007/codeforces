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

int val[300007];
vector<pair<int,int>>G[300007];
int o[300007];
int s[300007];
vector<int>ans_front;
vector<int>ans_back;
int x;

int Find(int v)
{
    while(true)
    {
        if(o[v]==v) return v;
        v=o[v];
    }
}
void Onion(int u,int v)
{
    if(s[u]<=s[v])
    {
        o[u]=v;
        s[v]+=s[u];
    }
    else
    {
        o[v]=u;
        s[u]+=s[v];
    }
}

void dfs(int v,int o,int k)
{
    for(auto u:G[v])
    {
        if(u.st==o) continue;
        dfs(u.st,v,u.nd);
    }
    if(k!=-1)
    {
        if(val[v]>=x)
        {
            ans_front.pb(k);
            val[o]+=val[v]-x;
        }
        else ans_back.pb(k);
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
        int n,m,a,b,sum=0;
        cin>>n>>m>>x;
        for(int i=1;i<=n;i++)
        {
            cin>>val[i];
            sum+=val[i];
        }
        vector<pair<pair<int,int>,int>>kraw;
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            kraw.pb({{a,b},i});
        }
        if(sum<x*(n-1))
        {
            cout<<"NO";
            return 0;
        }
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
        {
            o[i]=i;
            s[i]=1;
        }
        for(auto xd:kraw)
        {
            if(Find(xd.st.st)!=Find(xd.st.nd))
            {
                Onion(Find(xd.st.st),Find(xd.st.nd));
                G[xd.st.st].pb({xd.st.nd,xd.nd});
                G[xd.st.nd].pb({xd.st.st,xd.nd});
            }
        }
        dfs(1,-1,-1);
        reverse(ans_back.begin(),ans_back.end());
        for(auto xd:ans_front) cout<<xd<<endl;
        for(auto xd:ans_back) cout<<xd<<endl;
    }

    return 0;
}