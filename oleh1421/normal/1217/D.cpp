#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
///#define int long long
typedef long long ll;
using namespace std;
vector<int>g[20001];
int used[20001];
bool ok=true;
void dfs(int v){
     used[v]=1;
     for (auto to:g[v]){
         if (used[to]==1){
            ok=false;
         } else if (used[to]==0){
            dfs(to);
         }
     }
     used[v]=2;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    vector<pair<int,int> >v;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        v.push_back({a,b});
    }
    for (int i=1;i<=n;i++){
        if (used[i]==0){
            dfs(i);
        }
    }
    if (ok){
        cout<<1<<endl;
        for (int i=1;i<=m;i++) cout<<1<<" ";
        return 0;
    }
    cout<<2<<endl;
    for (int i=0;i<m;i++) cout<<(v[i].first>v[i].second)+1<<" ";
    return 0;
}