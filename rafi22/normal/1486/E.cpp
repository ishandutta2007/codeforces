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

const bool multi=0;

vector<pair<int,int>>G[51*100007];
int d[51*100007];
vector<pair<int,int> >g[100007];
set<pair<int,int>>Q;


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
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            g[a].pb({b,c});
            g[b].pb({a,c});
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=50;j++)
            {
                for(auto u:g[i])
                {
                    G[(i-1)*51+1+j].pb({51*(u.st-1)+1,(j+u.nd)*(j+u.nd)});
                }
            }
            for(auto u:g[i]) G[(i-1)*51+1].pb({51*(u.st-1)+1+u.nd,0});
        }

        for(int i=1; i<=51*n; i++) d[i]=mod;
        d[1]=0;
        Q.insert({0,1});
        while(!Q.empty())
        {
            pair<int,int> p=*Q.begin();
            Q.erase(Q.begin());
            int v=p.nd;
            for(auto u:G[v])
            {
                if(d[u.st]>d[v]+u.nd)
                {
                    Q.erase({d[u.st],u.st});
                    d[u.st]=d[v]+u.nd;
                    Q.insert({d[u.st],u.st});
                }
            }
        }
        for(int i=1;i<=51*n;i+=51)
        {
        	if(d[i]==mod) cout<<-1<<" ";
        	else cout<<d[i]<<" ";
        }
    }
    return 0;
}