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

set<pair<int,int>>fre[107];
vector<int>ans[107];
int b[107][107];

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
        vector<pair<int,pair<int,int>>>vec;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>b[i][j];
                vec.pb({b[i][j],{i,j}});
                fre[i].insert({j,b[i][j]});
            }
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<m;i++) fre[vec[i].nd.st].erase({vec[i].nd.nd,vec[i].st});
        for(int i=0;i<m;i++)
        {
            int c=vec[i].nd.st;
            ans[c].pb(vec[i].st);
            for(int j=1;j<=n;j++)
            {
                if(j==c) continue;
                pair<int,int>p=*fre[j].begin();
                fre[j].erase(p);
                ans[j].pb(p.nd);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(auto x:ans[i]) cout<<x<<" ";
            cout<<endl;
            ans[i].clear();
        }
    }

    return 0;
}