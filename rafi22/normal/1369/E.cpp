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

bool was[200007];
bool odw[100007];
int ile[100007];
vector<pair<int,int>>G[100007];
int w[100007];

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
        for(int i=1;i<=n;i++) cin>>w[i];
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            G[a].pb({b,i});
            G[b].pb({a,i});
        }
        vector<int>ans;
        deque<int>Q;
        for(int i=1;i<=n;i++)
        {
            ile[i]=sz(G[i]);
            if(ile[i]<=w[i])
            {
                odw[i]=1;
                Q.pb(i);
            }
        }
        while(!Q.empty())
        {
            int v=Q[0];
            Q.pop_front();
            for(auto u:G[v])
            {
                if(was[u.nd]) continue;
                was[u.nd]=1;
                ans.pb(u.nd);
                ile[u.st]--;
                if(!odw[u.st]&&ile[u.st]<=w[u.st])
                {
                    odw[u.st]=1;
                    Q.pb(u.st);
                }
            }
        }
        if(sz(ans)<m) cout<<"DEAD";
        else
        {
            cout<<"ALIVE"<<endl;
            reverse(ans.begin(),ans.end());
            for(auto x:ans) cout<<x<<" ";
        }
    }

    return 0;
}