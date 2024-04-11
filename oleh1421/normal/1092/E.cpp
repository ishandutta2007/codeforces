#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#include <experimental/algorithm>
#define endl '\n'
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
vector<int>g[200001];
int dfs(int v,int pr){
    int maxx=0;
    for (auto to:g[v]){
        if (to!=pr) maxx=max(maxx,dfs(to,v));
    }
    return maxx+1;
}
vector<int>u;
bool used[200001];
void dfs1(int v){
    u.push_back(v);
    used[v]=true;
    for (auto to:g[v]){
        if (!used[to]) dfs1(to);
    }
}
int32_t main() {
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<pair<int,int> >x;
    int d=0;
    int minD=1000000001;

    for (int i=1;i<=n;i++){
        if (used[i]) continue;
        u.clear();
        dfs1(i);
        int minx=10000001;
        int maxx=0;
        int ind=0;
        for (auto v:u){
            int cur=dfs(v,0);
            maxx=max(maxx,cur);
            d=max(d,cur);
            if (cur<minx){
                ind=v;
                minx=cur;
            }
        }
        x.push_back({-maxx,ind});
    }
    sort(x.begin(),x.end());
    vector<pair<int,int> >ans;
    for (int i=1;i<x.size();i++){
        ans.push_back({x[0].second,x[i].second});
        g[x[0].second].push_back(x[i].second);
        g[x[i].second].push_back(x[0].second);
    }
    int maxx=0;
    for (int i=1;i<=n;i++) maxx=max(maxx,dfs(i,0));
    cout<<maxx-1<<endl;
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;
    return 0;
}


///2007521364118