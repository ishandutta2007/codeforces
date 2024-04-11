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

const bool multi=1;

int c[500007];
vector<int>G[500007];

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
        for(int i=1;i<=n;i++) cin>>c[i];
        vector<pair<vector<int>,int>>vec;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            G[b].pb(a);
        }
        for(int i=1;i<=n;i++)
        {
            sort(G[i].begin(),G[i].end());
            if(sz(G[i])==0) continue;
            vec.pb({G[i],c[i]});
        }
        sort(vec.begin(),vec.end());
        int ans=-1,act=vec[0].nd;
        for(int i=1;i<sz(vec);i++)
        {
            if(vec[i].st!=vec[i-1].st)
            {
                if(ans==-1) ans=act;
                else ans=__gcd(ans,act);
                act=vec[i].nd;
            }
            else act+=vec[i].nd;
        }
        if(ans==-1) ans=act;
        else ans=__gcd(ans,act);
        cout<<ans<<endl;
        for(int i=1;i<=n;i++) G[i].clear();
    }

    return 0;
}