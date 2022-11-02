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

const int N=1007;

vector<int>G[N];
int a[N];
int ile[N];

signed main()
{
    mod=mod1;
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
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
            ile[i]=0;
        }
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            G[x].pb(y);
            ile[y]++;
        }
        int res=-1;
        for(int i=1;i<=2*m;i++)
        {
            vector<int>S;
            for(int j=1;j<=n;j++)
            {
                if(a[j]>0) S.pb(j);
            }
            if(sz(S)==0)
            {
                res=i-1;
                break;
            }
            for(auto v:S)
            {
                a[v]--;
                for(auto u:G[v]) a[u]++;
            }
        }
        if(res!=-1)
        {
            cout<<res<<endl;
            continue;
        }
        for(int i=1;i<=n;i++) a[i]%=mod;
        deque<int>Q;
        for(int i=1;i<=n;i++) if(ile[i]==0) Q.pb(i);
        while(sz(Q)>0)
        {
            int v=Q[0];
            Q.pop_front();
            for(auto u:G[v])
            {
                a[u]=(a[u]+a[v])%mod;
                ile[u]--;
                if(ile[u]==0) Q.pb(u);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(sz(G[i])==0) cout<<(a[i]+2*m)%mod<<endl;
        }
    }

    return 0;
}