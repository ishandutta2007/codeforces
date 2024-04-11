#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'

using namespace std;
vector<int>g[200001];
bool used[200001];
void dfs(int v){
    used[v]=true;
    for (auto to:g[v]){
        if (!used[to]) dfs(to);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    for (int i=1;i<=k;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (!used[i]){
            dfs(i);
            cnt++;
        }
    }
    cout<<k-n+cnt;
    return 0;
}