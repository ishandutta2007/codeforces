#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 610;
const ll inf = (ll)1e18;
vector<pii> E[N];

int n;
ll dist[N][N];
bool vis[N];
ll best[N];

void upd(ll &a, ll b){
    a = min(a, b);
}

int sub(int x){
    if(x >= n) return x - n;
    return x;
}

void solve(int node){
    for(int i = 0 ; i < n; i ++ ){
        dist[node][i] = inf;
        vis[i]=false;
    }
    dist[node][node] = 0;
    int cur;
    ll dis;
    ll mod;
    ll EC;

    for(int iq = 0; iq < n; iq ++ ){
        cur = -1;
        for(int j = 0 ; j < n; j ++ ){
            best[j]=inf;
            if(vis[j]) continue;
            if(cur == -1 || dist[node][j] < dist[node][cur]){
                cur = j;
            }
        }

        vis[cur] = true;
        dis = dist[node][cur];
        mod = (dis % n);
        for(auto x : E[cur]){
            upd(best[sub(mod + x.fi)], x.se - sub(mod + x.fi));
        }
        EC = inf;
        for(int target = 0; target < n; target ++ ){
            upd(EC, best[target]);
            if(dist[node][target] > dis + target + EC){
                dist[node][target] = dis + target + EC;
            }
        }
        EC = inf;
        for(int target = n - 1; target >= 0; target -- ){
            upd(EC, best[target] + n);
            if(dist[node][target] > dis + target + EC){
                dist[node][target] = dis + target + EC;
            }
        }
    }
}

int main(){
    fastIO;
    int m;
    cin >> n >> m;
    ll u, v, w;
    for(int i = 0 ; i < m; i ++ ){
        cin >> u >> v >> w;
        E[u].push_back(mp(v, w));
    }
    for(int i = 0 ; i < n; i ++ ){
        solve(i);
    }
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < n; j ++ ){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}