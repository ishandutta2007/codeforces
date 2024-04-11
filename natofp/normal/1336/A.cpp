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

const int nax = 2e5 + 5;
vector<int> adj[nax];
int dp[nax];
int sz[nax];
int n;
int taken[nax];

ll ans = 0;

void dfs(int v, int p){
    sz[v] = 1;
    for(int x : adj[v]){
        if(x != p){
            dp[x] = dp[v] + 1;
            dfs(x, v);
            sz[v] += sz[x];
        }
    }
}

void calc(int v, int p, int sum){
    if(taken[v]) ans += sum;
    sum += (!taken[v]);
    for(int x : adj[v]){
        if(x != p){
            calc(x, v, sum);
        }
    }
}

void solve(){
    cin >> n;
    int k; cin >> k;
    for(int i=1;i<n;i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 1);
    vector<pii> s;
    for(int i=1;i<=n;i++){
        s.pb(mp(dp[i] - sz[i], i));
    }
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    for(int i=0;i<n;i++){
        taken[s[i].nd] = true;
        k--;
        if(!k) break;
    }
    calc(1, 1, 0);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}