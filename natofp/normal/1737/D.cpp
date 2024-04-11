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

const int nax = 505;
ll len1[nax][nax];

const ll inf = 1e18;
vector<pii> adj[nax];
ll somsiad[nax];

void solve(){
    int n, m; cin >> n >> m;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++){
        somsiad[i] = inf;
        for(int j=1;j<=n;j++){
            len1[i][j] = inf;

            if(i == j){
                len1[i][j] = 0;

            }
        }
    }
    for(int i=1;i<=m;i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].pb(mp(y, w));
        adj[y].pb(mp(x, w));
        len1[x][y] = len1[y][x] = 1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                len1[i][j] = min(len1[i][j], len1[i][k] + len1[k][j]);
            }
        }
    }

    ll ans = inf;
    for(int i=1;i<=n;i++){
        int from = i;
        for(pii cur : adj[i]){
            int to = cur.st;
            ll w = cur.nd;
            ll sumdist = min(len1[from][1] + len1[to][n], len1[from][n] + len1[to][1]) + 1;
            ans = min(ans, sumdist * w);

            for(int k=1;k<=n;k++){
                ll xd = len1[k][1] + len1[k][n] + len1[k][from];
                ans = min(ans, (xd + 2) * w);
            }

        }
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