#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int>g[500001];
bool used[500001];
vector<int>u;
void dfs(int v){
     u.push_back(v);
     used[v]=true;
     for (auto to:g[v]){
        if (!used[to]) dfs(to);
     }
}
int ans[500001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int k;cin>>k;
        int last=0;
        for (int j=1;j<=k;j++){
            int cur;cin>>cur;
            if (last){
                g[last].push_back(cur);
                g[cur].push_back(last);
            }
            last=cur;
        }
    }
    for (int i=1;i<=n;i++){
         if (!used[i]){
             u.clear();
             dfs(i);
             int k=(int)u.size();
             for (auto j:u) ans[j]=k;
         }
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}
//2 6 -2 -6  2