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
#define mt make_tuple

using namespace std;

const int nax = 2e5 + 5;
vector<int> adj[nax];
int n;
ll l[nax];
ll r[nax];
ll ans;

ll dfs(int v, int p){
    ll canUse = 0;
    for(int x : adj[v]){
        if(x != p){
            canUse += dfs(x, v);
        }
    }
    if(canUse < l[v]){
        ans++;
        canUse = r[v];
    }
    return min(canUse, r[v]);
}

void solve(){
    ans = 0;
    cin >> n;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=2;i<=n;i++){
        int p; cin >> p;
        adj[i].pb(p);
        adj[p].pb(i);
    }
    for(int i=1;i<=n;i++) cin >> l[i] >> r[i];
    dfs(1, 1);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}