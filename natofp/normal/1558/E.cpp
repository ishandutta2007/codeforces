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

const int nax = 2005;
int a[nax];
int b[nax];
vector<int> adj[nax];
int n, m;

bool component[nax];
int beforeDFS[nax];
bool vis[nax];
int take[nax];
bool found = false;

void dfs(int v, ll power, int from){
    vis[v] = true;
    if(!component[v]) power += b[v];
    for(int x : adj[v]){
        if(x == from) continue;
        if(component[x] && component[v]) continue;
        if(found) return;
        if(!vis[x] && power > a[x]){
            beforeDFS[x] = v;
            dfs(x, power, v);
        }
        else if(vis[x]){
            int p = v;
            take[p] = true;
            while(beforeDFS[p]){
                p = beforeDFS[p];
                take[p] = true;
            }
            p = x;
            take[x] = true;
            while(beforeDFS[p]){
                p = beforeDFS[p];
                take[p] = true;
            }
            found = true;
        }
    }
}

bool can(ll startPower){
    for(int i=1;i<=n;i++) component[i] = false;
    component[1] = true;
    while(1){
        for(int i=1;i<=n;i++) beforeDFS[i] = 0;
        for(int i=1;i<=n;i++) take[i] = false;
        for(int i=1;i<=n;i++) vis[i] = component[i];
        found = false;
        for(int i=1;i<=n;i++){
            if(!found && component[i]) dfs(i, startPower, -1);
        }
        if(!found) break;
        for(int i=1;i<=n;i++){
            if(take[i]){
                if(!component[i]){
                    component[i] = true;
                    startPower += b[i];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!component[i]) return false;
    }
    return true;
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=2;i<=n;i++) cin >> a[i];
    for(int i=2;i<=n;i++) cin >> b[i];
    for(int i=1;i<=m;i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int lo = 0;
    int hi = 1000 * 1000 * 1001;
    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if(can(mid)) hi = mid;
        else lo = mid + 1;
    }
    ll ans = hi;
    if(can(lo)) ans = lo;
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}