//#pragma GCC opitmize ("trapv")
//#pragma GCC opitmize ("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
int h[N];
int tin[N];
int tout[N];
int timer=0;
vector<int>g[N];
int p[N];
void dfs(int v,int pr,int cur){
    p[v]=pr;
    h[v]=cur;
    tin[v]=++timer;
    for (auto to:g[v]){
        if (to!=pr){
            dfs(to,v,cur+1);
        }
    }
    tout[v]=timer;
}
bool upper(int a,int b){
    return (tin[a]<=tin[b] && tout[a]>=tout[b]);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,1);
    while (m--){
        int k;cin>>k;
        vector<pair<int,int> >v;
        for (int i=1;i<=k;i++){
            int u;cin>>u;
            if (u>1) v.push_back({h[p[u]],p[u]});
        }
        sort(v.begin(),v.end());
        bool ok=true;
        for (int i=1;i<v.size();i++){
            if (!upper(v[i-1].second,v[i].second)) ok=false;
        }
        if (ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
/*
10 100
1 99
1 3
1 3
1 3
1 3
1 3
1 3
1 3
1 3
1 3
*/