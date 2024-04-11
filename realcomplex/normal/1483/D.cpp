#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 610;
const int M = N * N;
const ll inf = (ll)1e18;
const int MAX = (int)2e9;
int u[M], v[M];
ll w[M];

ll D[N][N];
ll low[N];
bool use[M];
vector<pii> Q[N];

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            D[i][j]=inf;
        }
        D[i][i]=0;
    }
    for(int i = 1; i <= m; i ++ ){
        cin >> u[i] >> v[i] >> w[i];
        D[u[i]][v[i]] = w[i];
        D[v[i]][u[i]] = w[i];
    }
    for(int k = 1; k <= n; k ++ ){
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= n; j ++ ){
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    int uu, vv, wd;
    for(int i = 1; i <= q; i ++ ){
        cin >> uu >> vv >> wd;
        Q[uu].push_back(mp(vv, wd));
        Q[vv].push_back(mp(uu, wd));
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            low[j] = inf;
        }
        for(auto x : Q[i]){
            for(int j = 1; j <= n; j ++ ){
                low[j] = min(low[j], D[x.fi][j] + (MAX - x.se));
            }
        }
        for(int j = 1; j <= m ; j ++ ){
            if(D[i][u[j]] + w[j] + low[v[j]] <= MAX){
                use[j]=true;
            }
            if(D[i][v[j]] + w[j] + low[u[j]] <= MAX){
                use[j]=true;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= m; i ++ ){
        cnt += use[i];
    }
    cout << cnt << "\n";
    return 0;
}