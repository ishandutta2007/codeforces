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

const int nax = 4e5 + 5;
vector<int> adj[nax];
bool vis[nax];

int a[nax];
int b[nax];

const int mod = 1e9 + 7;
void dfs(int v){
    vis[v] = true;
    for(int x : adj[v]){
        if(vis[x] == false) dfs(x);
    }
}

void solve(){
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++) vis[i] = false;
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++){
        adj[a[i]].pb(b[i]);
    }
    int c = 0;
    for(int i=1;i<=n;i++){
        if(vis[i] == false){
            c++;
            dfs(i);
        }
    }
    int ans = 1;
    while(c--){
        ans *= 2;
        ans %= mod;
    }
    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}