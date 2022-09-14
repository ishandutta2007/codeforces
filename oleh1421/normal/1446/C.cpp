#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010*33;
int a[N];
int dp[N];
int go[N][2];
int timer=1;
bool terminal[N];
void add(int x){
    int v=1;
    for (int i=29;i>=0;i--){
        int cur=((x>>i)&1);
        if (!go[v][cur]) go[v][cur]=++timer;
        v=go[v][cur];
    }
    terminal[v]=true;
}
void dfs(int v){
    if (!v) return;
    if (terminal[v]){
        dp[v]=1;
        return;
    }
    dfs(go[v][0]);
    dfs(go[v][1]);
    if (!go[v][0]) dp[v]=dp[go[v][1]];
    else if (!go[v][1]) dp[v]=dp[go[v][0]];
    else dp[v]=max(dp[go[v][0]],dp[go[v][1]])+min({dp[go[v][0]],dp[go[v][1]],1});
}
void solve(){
    set<int>st;
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        add(a[i]);
    }
    dfs(1);
    cout<<n-dp[1]<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}