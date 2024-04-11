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

int d[1000007];
bool c[1000007];
vector<int>G[1000007];
bool odw[1000007];

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
        int n,m,a,b,c;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            if(c==0)
            {
                G[2*b].pb(2*a);
                G[2*b+1].pb(2*a);
            }
            else
            {
                G[2*b].pb(2*a+1);
                G[2*b+1].pb(2*a+1);
            }
        }
        for(int i=1;i<=2*n;i++) d[i]=inf;
        d[2*n]=0;
        d[2*n+1]=0;
        odw[2*n]=1;
        odw[2*n+1]=1;
        deque<int>Q;
        Q.pb(2*n);
        while(!Q.empty())
        {
            int v=Q[0];
            Q.pop_front();
            odw[v]=1;
            if(!odw[v^1]) continue;
            for(auto u:G[v])
            {
                if(d[u]!=inf) continue;
                d[u]=d[v]+1;
                Q.pb(u);
            }
        }
        if(max(d[2],d[3])==inf) cout<<-1<<endl;
        else cout<<max(d[2],d[3])<<endl;
        for(int i=1;i<=n;i++)
        {
            if(d[2*i]>d[2*i+1]) cout<<0;
            else cout<<1;
        }
    }

    return 0;
}