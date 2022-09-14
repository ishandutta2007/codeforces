#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define next a
typedef long long ll;
using namespace std;
int next[1000001];
int timer=0;
vector<int>g[1000001];
int p[1000001];
void dfs(int v){
     p[v]=timer--;
     for (auto to:g[v]) dfs(to);
}
void solve(){
     int n;cin>>n;
     for (int i=1;i<=n;i++) cin>>next[i];
     for (int i=1;i<=n+1;i++) g[i].clear();
     for (int i=1;i<=n;i++){
         if (next[i]==-1) next[i]=i+1;
         g[next[i]].push_back(i);
     }
     timer=n+1;
     dfs(n+1);
     vector<pair<int,int> >v;
     v.push_back({n+1,n+1});
     for (int i=n;i>0;i--){
          while (v.back().first<p[i]) v.pop_back();
          if (v.back().second!=next[i]){
             cout<<"-1\n";
             return;
          }
          v.push_back({p[i],i});
     }
    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--) solve();
    return 0;
}