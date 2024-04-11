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

const bool multi=1;

int o[200007];
int Find(int v)
{
    if(o[v]==v) return v;
    return o[v]=Find(o[v]);
}
void Union(int u,int v)
{
    o[u]=o[v];
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
        vector<pair<int,pair<int,int>>>V(m);
        vector<bool>ban(m,0);
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>w;
            V[i]={w,{a,b}};
        }
        int ans=(1<<30)-1;
        for(int j=29;j>=0;j--)
        {
            for(int i=1;i<=n;i++) o[i]=i;
            int c=0;
            for(int i=0;i<m;i++)
            {
                if(ban[i]) continue;
                if((V[i].st&(1<<j))) continue;
                int u=Find(V[i].nd.st),v=Find(V[i].nd.nd);
                if(u!=v)
                {
                    c++;
                    Union(u,v);
                }
            }
            if(c==n-1)
            {
                ans-=1<<j;
                for(int i=0;i<m;i++) if((V[i].st&(1<<j))) ban[i]=1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}