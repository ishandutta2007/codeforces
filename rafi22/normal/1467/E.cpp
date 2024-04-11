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

const int N=200007;
int a[N];
map<int,int>mapa;
vector<int>temp;
vector<int>G[N];
bool odw[N];
int pre[N];
int post[N];
int c;
int seg[4*N],pot=1;
vector<int> vec[N];
void dfs(int v)
{
    pre[v]=++c;
    odw[v]=1;
    for(auto u:G[v])
    {
        if(!odw[u]) dfs(u);
    }
    post[v]=c;
}
int que(int v)
{
    int res=0;
    int y=v+pot-1;
    while(y>0)
    {
        res+=seg[y];
        y/=2;
    }
    return res;
}
void ins(int v,int a,int b,int l,int r,int val)
{
    if(a<=l&&b>=r)
    {
        seg[v]+=val;
        return;
    }
    if(r<a||l>b) return;
    ins(2*v,a,b,l,(l+r)/2,val);
    ins(2*v+1,a,b,(l+r)/2+1,r,val);
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
        int n;
        cin>>n;
        while(pot<n) pot*=2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            temp.pb(a[i]);
        }
        sort(temp.begin(),temp.end());
        int it=1;
        mapa[temp[0]]=1;
        for(int i=1;i<sz(temp);i++)
        {
            if(temp[i]!=temp[i-1]) mapa[temp[i]]=++it;
        }
        for(int i=1;i<=n;i++) a[i]=mapa[a[i]];
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
        }
        dfs(1);
        for(int i=1;i<=n;i++) vec[a[i]].pb(i);
        for(int i=1;i<=n;i++)
        {
            int mn=inf,mx=0;
            for(auto v:vec[i])
            {
                mn=min(mn,pre[v]);
                mx=max(mx,pre[v]);
            }
            for(auto v:vec[i])
            {
                if(mn<pre[v]||mx>post[v])
                {
                    ins(1,pre[v],post[v],1,pot,1);
                }
            }
            set<int> xd;
            xd.insert(inf);
            for(auto v:vec[i]) xd.insert(pre[v]);
            for(auto v:vec[i])
            {
                int p=-1,cnt=0;
                for(auto u:G[v])
                {
                    if(pre[u]>pre[v])
                    {
                        if(*xd.lower_bound(pre[u])<=post[u])
                        {
                            p=u;
                            cnt++;
                        }
                    }
                }
                if(cnt) ins(1,1,n,1,pot,1);
                if(cnt==1) ins(1,pre[p],post[p],1,pot,-1);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++) if(!que(i)) ans++;
        cout<<ans;

    }

    return 0;
}