#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;
const int K = 20;
const int MOD = 998244353;
vector<pii> T[N];

int dp[N][K][2];

struct S{
    int node;
    int tr;
    int dg;
};

pii dist[N][2];
bool vis[N][2];

bool comp(pii a, pii b){
    if(a.fi == b.fi)
        return (a.se < b.se);
    if(a.fi < 40 && b.fi < 40){
        ll x = (1ll << a.fi) - 1 + a.se;
        ll y = (1ll << b.fi) - 1 + b.se;
        return (x < y);
    }
    else{
        return a.fi < b.fi;
    }
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 0; i < m ; i ++ ){
        cin >> u >> v;
        T[u].push_back(mp(v,0));
        T[v].push_back(mp(u,1));
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 0 ; j < K ; j ++ ){
            for(int x = 0; x < 2; x ++ ){
                dp[i][j][x] = (int)1e9;
            }
        }
    }
    dp[1][0][1] = 0;
    queue<S> bf;
    bf.push({1, 0, 1});
    int node;
    int chn;
    int las;
    int nw;
    int need;
    while(!bf.empty()){
        node = bf.front().node;
        chn = bf.front().tr;
        las = bf.front().dg;
        bf.pop();
        for(auto x : T[node]){
            nw = chn;
            need = x.se ^ (chn % 2);
            nw += need;
            if(nw >= K) continue;
            if(dp[x.fi][nw][x.se] == (int)1e9){
                dp[x.fi][nw][x.se] = dp[node][chn][las] + 1;
                bf.push({x.fi, nw, x.se});
            }
        }
    }

    for(int i = 1; i <= n; i ++ ){
        for(int j = 0 ;j < 2; j ++ ){
            dist[i][j] = mp((int)1e9, (int)1e9);
        }
    }
    priority_queue<pair<pii,pii>, vector<pair<pii,pii>>, greater<pair<pii,pii>>> si;
    for(int j = 1 ; j < 2; j ++ ){
        si.push(mp(mp(0, 0), mp(1, j)));
    }
    int bit;
    pii nex;
    dist[1][1] = mp(0, 0);
    while(!si.empty()){
        node = si.top().se.fi;
        bit = si.top().se.se;
        si.pop();
        if(vis[node][bit]){
            continue;
        }
        vis[node][bit]=true;
        for(auto xy : T[node]){
            nex = dist[node][bit];
            nex.se ++ ;
            nex.fi += ((nex.fi&1) ^ (xy.se));
            if(dist[xy.fi][xy.se] > nex){
                dist[xy.fi][xy.se] = nex;
                si.push(mp(nex, xy));
            }
        }
    }
    vector<pii> cand;
    if(vis[n][0]){
        cand.push_back(dist[n][0]);
    }
    if(vis[n][1]){
        cand.push_back(dist[n][1]);
    }
    for(int lg = 0; lg < K; lg ++ ){
        for(int st = 0; st < 2; st ++ ){
            if(dp[n][lg][st] != (int)1e9){
                cand.push_back(mp(lg, dp[n][lg][st]));
            }
        }
    }
    sort(cand.begin(), cand.end(), comp);
    ll sol = 1;
    for(int i = 0 ;i < cand[0].fi; i ++ ){
        sol = (sol * 2ll) % MOD;
    }
    sol = (sol + MOD - 1) % MOD;
    sol = (sol + cand[0].se) % MOD;
    cout << sol << "\n";
    return 0;
}