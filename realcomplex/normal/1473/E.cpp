#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const ll inf = (ll)1e18;
vector<pii> E[N];
ll dp[N][2][2];
bool vis[N][2][2];

struct State{
    ll cost;
    int node;
    int ci;
    int cj;
    bool operator< (const State &Q) const {
        return cost > Q.cost;
    }
};

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for(int t= 0 ; t < m ; t ++ ){
        cin >> u >> v >> w;
        E[u].push_back(mp(v,w));
        E[v].push_back(mp(u,w));
    }
    for(int i = 1; i <= n; i ++ ){
        for(int p = 0 ; p < 2; p ++ ){
            for(int q = 0; q < 2; q ++ ){
                dp[i][p][q]=inf;
            }
        }
    }
    dp[1][0][0]=0;
    priority_queue<State> pq;
    pq.push({0,1,0,0});
    ll wei;
    int node;
    int b0, q0;
    ll nx_cost;
    int n0, m0;
    while(!pq.empty()){
        wei = pq.top().cost;
        node = pq.top().node;
        b0 = pq.top().ci;
        q0 = pq.top().cj;
        pq.pop();
        if(vis[node][b0][q0]) continue;
        vis[node][b0][q0]=true;
        for(int d0 = 0; d0 <= (1-b0); d0 ++ ){
            for(int d1 = 0 ; d1 <= (1-q0); d1 ++ ){
                for(auto x : E[node]){
                    n0 = b0 | d0;
                    m0 = q0 | d1;
                    nx_cost = dp[node][b0][q0] + x.se - d0 * 1ll * x.se + d1 * 1ll * x.se;
                    if(dp[x.fi][n0][m0] > nx_cost){
                        dp[x.fi][n0][m0] = nx_cost;
                        pq.push({nx_cost, x.fi, n0, m0});
                    }
                }
            }
        }
    }
    for(int i = 2; i <= n; i ++ ){
        cout << dp[i][1][1] << " ";
    }

    return 0;
}