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

const int N=200007;

vector<int>G[N];
int d[N];
int deg[N];
bool odw[N];

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
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            deg[a]++;
            G[b].pb(a);
        }
        for(int i=1;i<=n;i++) d[i]=inf;
        priority_queue<pair<int,int>>Q;
        d[n]=0;
        Q.push({0,n});
        while(!Q.empty())
        {
            int v=Q.top().nd;
            int t=-Q.top().st;
            Q.pop();
            if(odw[v]) continue;
            odw[v]=1;
            for(auto u:G[v])
            {
                deg[u]--;
                if(t+1+deg[u]<d[u]) d[u]=t+1+deg[u];
                Q.push({-d[u],u});
            }
        }
        cout<<d[1]<<endl;
    }

    return 0;
}