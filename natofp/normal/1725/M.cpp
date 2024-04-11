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

const int nax = 1e5 + 5;
vector<pll> adj[nax];
vector<pll> adj2[nax];
int n, m;
ll dist[nax];
const ll inf = 1e18;

void prep(){
    for(int i=1;i<=n;i++) dist[i] = inf;
    priority_queue<pll> Q;
    Q.push(mp(0, 1));
    dist[1] = 0;
    while(!Q.empty()){
        pll cur = Q.top();
        Q.pop();
        if(dist[cur.nd] != -cur.st) continue;
        int who = cur.nd;
        ll di = -cur.st;
        for(pll edge : adj2[who]){
            if(di + edge.nd < dist[edge.st]){
                dist[edge.st] = di + edge.nd;
                Q.push(mp(-dist[edge.st], edge.st));
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        ll x, y, w; cin >> x >> y >> w;
        adj[y].pb(mp(x, w));
        adj2[x].pb(mp(y, w));
    }
    prep();
    priority_queue<pll> Q;
    for(int i=1;i<=n;i++) Q.push(mp(-dist[i], i));
    while(!Q.empty()){
        pll cur = Q.top();
        Q.pop();
        if(dist[cur.nd] != -cur.st) continue;
        int who = cur.nd;
        ll di = -cur.st;
        for(pll edge : adj[who]){
            if(di + edge.nd < dist[edge.st]){
                dist[edge.st] = di + edge.nd;
                Q.push(mp(-dist[edge.st], edge.st));
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(dist[i] == inf) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}