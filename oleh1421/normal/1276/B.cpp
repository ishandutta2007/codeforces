#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
bool used[300001];
vector<int>g[300001];
ll cnt=0;
ll n,m,a,b;
void dfs(int v){
    if (used[v]) return;
    if (v!=b && v!=a) cnt++;
    used[v]=true;
    for (auto to:g[v]){
        dfs(to);
    }
}
void cls(int n){
    for (int i=0;i<=n;i++) used[i]=false;
}
void solve(){
    for (int i=0;i<=n;i++) g[i].clear();
    cin>>n>>m>>a>>b;
    for (int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll sumA=0ll;
    ll sumB=0ll;
    ll sumAB=0ll;
    cls(n);
    used[b]=true;
    dfs(a);
    sumA=n-2-cnt;
    cnt=0;
    cls(n);
    used[a]=true;
    dfs(b);
    sumB=n-2-cnt;
    cnt=0;
    cout<<sumA*sumB<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}