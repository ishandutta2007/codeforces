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

vector<int>G[200007];
vector<int>RG[200007];
int ile[200007];
int DP[200007];

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
        int n,k,a;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>k;
            while(k--)
            {
                cin>>a;
                G[a].pb(i);
                RG[i].pb(a);
                ile[i]++;
            }
        }
        deque<int>Q;
        for(int i=1;i<=n;i++)
        {
            if(ile[i]==0)
            {
                Q.pb(i);
                DP[i]=1;
            }
        }
        int ans=0;
        while(!Q.empty())
        {
            int v=Q[0];
            Q.pop_front();
            for(auto u:RG[v])
            {
                if(u<v) DP[v]=max(DP[v],DP[u]);
                else DP[v]=max(DP[v],DP[u]+1);
            }
            ans=max(ans,DP[v]);
            for(auto u:G[v])
            {
                ile[u]--;
                if(ile[u]==0) Q.pb(u);
            }
        }
        for(int i=1;i<=n;i++) if(ile[i]>0) ans=-1;
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)
        {
            ile[i]=0;
            DP[i]=0;
            G[i].clear();
            RG[i].clear();
        }
    }

    return 0;
}