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

int o[600007];
int color[600007];
int must[600007];
int c[600007][3];
vector<int>dsu[600007];
vector<int>vec[300007];

int ans=0;
int Find(int v)
{
    while(true)
    {
        if(o[v]==v) return v;
        v=o[v];
    }
}
void Union(int u,int v,int a,int b)
{
   // cout<<u<<" "<<v<<" "<<a<<" "<<b<<endl;
    if(must[u]) ans-=c[u][must[u]];
    else ans-=min(c[u][1],c[u][2]);
    if(must[v]) ans-=c[v][must[v]];
    else ans-=min(c[v][1],c[v][2]);
    //cout<<ans<<endl;
    if(sz(dsu[u])>sz(dsu[v])) swap(u,v);
    o[u]=v;
    if(must[u])
    {
        if(color[a]==color[b]) must[v]=3-must[u];
        else must[v]=must[u];
    }
    //cout<<c[v][1]<<" "<<c[v][2]<<" "<<c[u][1]<<" "<<c[u][2]<<endl;
    if(color[a]==color[b])
    {
        c[v][1]+=c[u][2];
        c[v][2]+=c[u][1];
        while(sz(dsu[u])>0)
        {
            color[dsu[u].back()]=3-color[dsu[u].back()];
            dsu[v].pb(dsu[u].back());
            dsu[u].pop_back();
        }
    }
    else
    {
        c[v][1]+=c[u][1];
        c[v][2]+=c[u][2];
        while(sz(dsu[u])>0)
        {
            dsu[v].pb(dsu[u].back());
            dsu[u].pop_back();
        }
    }
    if(must[v]) ans+=c[v][must[v]];
    else ans+=min(c[v][1],c[v][2]);
   // cout<<ans<<endl;
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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        s='#'+s;
        for(int i=1;i<=k;i++)
        {
            int l,a;
            cin>>l;
            while(l--)
            {
                cin>>a;
                vec[a].pb(i);
            }
        }
        for(int i=1;i<=k;i++)
        {
            o[2*i]=2*i;
            o[2*i+1]=2*i;
            color[2*i]=1;
            color[2*i+1]=2;
            dsu[2*i].pb(2*i);
            dsu[2*i].pb(2*i+1);
            c[2*i][1]=1;
        }
        for(int i=1;i<=n;i++)
        {
            //cout<<sz(vec[i])<<endl;
            if(sz(vec[i])==1)
            {
              //  cout<<i<<" "<<vec[i][0]<<endl;
                if(s[i]=='0')
                {
                    int v=Find(2*vec[i][0]);
                 //   cout<<"XD"<<v<<endl;
                    if(!must[v])
                    {
                        must[v]=color[2*vec[i][0]];
                        ans-=min(c[v][1],c[v][2]);
                        ans+=c[v][must[v]];
                      //  cout<<v<<" "<<must[v]<<" "<<ans<<endl;
                    }
                }
                else
                {
                    int v=Find(2*vec[i][0]+1);
                    if(!must[v])
                    {
                        must[v]=color[2*vec[i][0]+1];
                        ans-=min(c[v][1],c[v][2]);
                        ans+=c[v][must[v]];
                    }
                }
            }
            else if(sz(vec[i])==2)
            {
               // cout<<vec[i][0]<<" "<<vec[i][1]<<endl;
                if(s[i]=='0')
                {
                    int u=Find(2*vec[i][0]+1),v=Find(2*vec[i][1]+1);
                    if(u!=v) Union(u,v,2*vec[i][0]+1,2*vec[i][1]+1);
                    u=Find(2*vec[i][0]),v=Find(2*vec[i][1]);
                    if(u!=v) Union(u,v,2*vec[i][0],2*vec[i][1]);
                }
                else
                {
                    //cout<<"xd"<<endl;
                    int u=Find(2*vec[i][0]),v=Find(2*vec[i][1]+1);
                    if(u!=v) Union(u,v,2*vec[i][0],2*vec[i][1]+1);
                    u=Find(2*vec[i][0]+1),v=Find(2*vec[i][1]);
                    if(u!=v) Union(u,v,2*vec[i][0]+1,2*vec[i][1]);
                }
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}