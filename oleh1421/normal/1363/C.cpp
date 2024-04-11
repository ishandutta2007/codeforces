//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=100025;
vector<int>g[N];
bool dp[N];
void dfs(int v,int pr){
    dp[v]=false;
    for (auto to:g[v]){
        if (to!=pr){
            dfs(to,v);
            dp[v]|=(dp[to]^1);
        }
    }
}
void solve(){
    int n,x;cin>>n>>x;
    for (int i=0;i<=n+1;i++) g[i].clear(),dp[i]=false;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (g[x].size()<=1){
        cout<<"Ayush\n";
        return;
    }
//    dfs(x,0);
    if (n%2) cout<<"Ashish\n";
    else cout<<"Ayush\n";
}
int main()
{
//    freopen("fuel.in","r",stdin);
//    freopen("fuel.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}