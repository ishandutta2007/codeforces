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

vector<int>G[100007];
int a[100007];
int b[100007];
int ile[100007];
int d[100007];
int o[100007];

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
        for(int i=1;i<=n;i++) cin>>b[i];
        int it=0;
        for(int i=1;i<=n;i++)
        {
            if(b[i]>0) a[++it]=b[i];
        }
        n=it;
        for(int i=1;i<=n;i++)
        {

            for(int j=60;j>=0;j--)
            {
                if((a[i]&(1LL<<j)))
                {
                    ile[j]++;
                    if(ile[j]>=3)
                    {
                        cout<<3;
                        return 0;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j&&(a[i]&a[j])>0) G[i].pb(j);
        int ans=inf;
        for(int i=1;i<=n;i++)
        {
            deque<int>Q;
            for(int j=1;j<=n;j++)
            {
                o[j]=0;
                d[j]=inf;
            }
            Q.pb(i);
            d[i]=0;
            while(!Q.empty())
            {
                int v=Q[0];
                Q.pop_front();
                for(auto u:G[v])
                {
                    if(d[u]!=inf&&u!=o[v])
                    {
                        ans=min(d[u]+d[v]+1,ans);
                    }
                    //cout<<v<<" "<<u<<endl;
                    if(d[u]!=inf) continue;
                    d[u]=d[v]+1;
                    o[u]=v;
                    Q.pb(u);
                }
            }
        }
        if(ans==inf) cout<<-1;
        else cout<<ans;
    }

    return 0;
}