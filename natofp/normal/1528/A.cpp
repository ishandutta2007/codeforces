#include <bits/stdc++.h>
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
int l[nax];
int r[nax];
int n;
ll dp[nax][2]; // min max

void dfs(int v, int p){
    ll sum0 = 0;
    ll sum1 = 0;
    for(int x : adj[v]){
        if(x != p){
            dfs(x, v);
            sum0 += max(abs(l[v] - l[x]) + dp[x][0], abs(l[v] - r[x]) + dp[x][1]);
            sum1 += max(abs(r[v] - l[x]) + dp[x][0], abs(r[v] - r[x]) + dp[x][1]);
        }
    }
    dp[v][0] = sum0;
    dp[v][1] = sum1;
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++) cin >> l[i] >> r[i];
    for(int i=1;i<n;i++){
        int x,y; cin >>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1, 1);
    cout << max(dp[1][0], dp[1][1]) << "\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();


    return 0;
}