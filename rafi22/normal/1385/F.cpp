#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

vector <int>G[200007];
bool odw[200007];
int leaves[200007];
int deg[200007];
deque <pair<int,int>> kolejka;

void clean(int n)
{
    for(int i=0;i<=n;i++)
    {
        odw[i]=0;
        deg[i]=0;
        leaves[i]=0;
        G[i].clear();
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
        int n,k,a,b;
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        for(int i=1;i<=n;i++)
        {
            deg[i]=G[i].size();
            if(G[i].size()==1)
            {
                leaves[G[i][0]]++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(leaves[i]>=k)
            {
                kolejka.pb({i,leaves[i]/k});
                leaves[i]%=k;
            }
        }
        int ans=0;
        while(!kolejka.empty())
        {
            int u=kolejka[0].st,x=kolejka[0].nd;
           // cout<<u<<endl;
            kolejka.pop_front();
            if(odw[u]) continue;
            ans+=x;
            int cnt=0;
            for(auto v:G[u])
            {
                if(!odw[v]&&deg[v]==1)
                {
                    cnt++;
                    odw[v]=1;
                }
                if(cnt==k*x) break;
            }
            deg[u]-=cnt;
            if(deg[u]==1)
            {
                for(auto v:G[u])
                {
                    if(deg[v]>1)
                    {
                        leaves[v]++;
                        if(leaves[v]>=k)
                        {
                            kolejka.pb({v,leaves[v]/k});
                            leaves[v]%=k;
                        }
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
        clean(n);
    }

    return 0;
}