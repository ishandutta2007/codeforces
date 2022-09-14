#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const ll mod=1000000007;
int used[200001];
int timer=0;
vector<int>g[200001];
int maxv[200001];
void dfs(int v){
    used[v]=timer;
    maxv[timer]=max(maxv[timer],v);
    for (auto to:g[v]){
        if (!used[to]) dfs(to);
    }
}
int r[200001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1;i<=n;i++){
        if (!used[i]){
            timer++;
            dfs(i);
        }
    }
    r[0]=0;
    int cnt=0;
    for (int i=1;i<=n;i++){
        r[i]=max(r[i-1],maxv[used[i]]);
        cnt+=(r[i]==i);
    }
    cout<<timer-cnt;

    return 0;
}