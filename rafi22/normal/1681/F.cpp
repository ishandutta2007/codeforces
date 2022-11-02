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

const int N=500007,pot=1<<19;

vector<pair<int,int>>G[N];
vector<int>X[N];
int pre[N],post[N],c;
int ile[N];

void dfs(int v,int o)
{
    pre[v]=++c;
    for(auto u:G[v])
    {
        if(u.st==o) continue;
        X[u.nd].pb(u.st);
        dfs(u.st,v);
    }
    post[v]=c;
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
            int a,b,c;
            cin>>a>>b>>c;
            G[a].pb({b,c});
            G[b].pb({a,c});
        }
        dfs(1,0);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
         //   cout<<"XD"<<i<<endl;
            vector<pair<int,int>>V;
            for(auto x:X[i])
            {
           //     cout<<x<<endl;
                V.pb({pre[x],post[x]});
                ile[pre[x]]=post[x]-pre[x]+1;
            }
            ile[1]=n;
            V.pb({1,n});
            sort(all(V));
            vector<pair<int,int>>Q;
            for(auto x:V)
            {
                while(sz(Q)>0&&Q.back().nd<x.st) Q.pop_back();
                if(sz(Q)>0) ile[Q.back().st]-=x.nd-x.st+1;
                Q.pb({x.st,x.nd});
            }
            Q.clear();
            for(auto x:V)
            {
                while(sz(Q)>0&&Q.back().nd<x.st) Q.pop_back();
                if(sz(Q)>0)
                {
                    ans+=ile[Q.back().st]*ile[x.st];
                //    cout<<ile[Q.back().st]<<" "<<ile[x.st]<<endl;
                }
                Q.pb({x.st,x.nd});
            }
        }
        cout<<ans;
    }

    return 0;
}