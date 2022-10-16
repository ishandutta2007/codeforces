#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = 1e5 + 5;
vector<int> adj[nax];
int dp[nax];

void dfs(int v, int p){
    dp[v] = dp[p] + 1;
    for(int x : adj[v]){
        if(x != p) dfs(x, v);
    }
}

void solve(){
    int n; cin >> n;
    for(int i=1;i<=n;i++) dp[i] = 0;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<n;i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 1);
    for(int i=1;i<=n;i++){
        int w = adj[i].size();
        if(dp[i] % 2) cout << w << " ";
        else cout << -w << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}