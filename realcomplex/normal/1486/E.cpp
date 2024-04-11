#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
const int M = 51;
const ll INF = (ll)1e18;
ll dp[N][M]; // 0 if havent
vector<pii> T[N];

ll sq(ll a){
    return (a * 1ll * a);
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for(int i = 1; i <= m ; i ++ ){
        cin >> u >> v >> w;
        T[u].push_back(mp(v, w));
        T[v].push_back(mp(u, w));
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 0 ; j < M ; j ++ ){
            dp[i][j]=INF;
        }
    }
    priority_queue<tuple<ll, int, int>> qq;
    qq.push({0ll,1,0});
    dp[1][0]=0;
    int node;
    int las;
    ll dd;
    while(!qq.empty()){
        tie(dd,node,las) = qq.top();
        dd=-dd;
        qq.pop();
        if(dp[node][las] != dd) continue;
        for(auto x : T[node]){
            if(las == 0){
                if(dp[x.fi][x.se] > dd){
                    dp[x.fi][x.se] = dd;
                    qq.push({-dp[x.fi][x.se], x.fi, x.se});
                }
            }
            else{
                if(dp[x.fi][0] > dd + sq(las + x.se)){
                    dp[x.fi][0] = dd + sq(las + x.se);
                    qq.push({-dp[x.fi][0], x.fi, 0});
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        if(dp[i][0] == INF){
            cout << "-1 ";
        }
        else{
            cout << dp[i][0] << " ";
        }
    }
    cout << "\n";
    return 0;
}