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

const int N=200007;

vector<int>G[N];
bool is[N];
vector<pair<int,int>>ans,ans1;
bool ok;

void dfs(int v,int o)
{
    vector<int>V[2];
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v);
        V[is[u]].pb(u);
    }
    while(true)
    {
        bool b=((sz(V[0])+sz(V[1])+(o!=0)-1))%2;
        if(sz(V[b])==0) break;
        ans.pb({V[b].back(),v});
        V[b].pop_back();
    }
    if(sz(V[0])>=2||sz(V[1])>=2) ok=0;
    else if(sz(V[0])==1)
    {
        ans1.pb({V[0][0],v});
        is[v]^=1;
    }
    else if(sz(V[1])==1) ok=0;
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
        int n;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        ok=1;
        ans.clear(),ans1.clear();
        dfs(1,0);
        if(!ok) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(auto x:ans) cout<<x.st<<" "<<x.nd<<endl;
            reverse(all(ans1));
            for(auto x:ans1) cout<<x.st<<" "<<x.nd<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
            is[i]=0;
        }
    }

    return 0;
}