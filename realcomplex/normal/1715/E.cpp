#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
const int K = 21;
const ll inf = (ll)1e18;
vector<pii> dd[N];
ll dp[N][K];
bool vis[N];
int n;

void layer(int id){
    priority_queue<pii,vector<pii>, greater<pii>> pq;
    for(int i = 1; i <= n; i ++ ){
        pq.push(mp(dp[i][id], (ll)i));
        vis[i]=false;
    }
    ll dist;
    int node;
    while(!pq.empty()){
        dist = pq.top().fi;
        node = pq.top().se;
        pq.pop();
        if(vis[node])continue;
        vis[node]=true;
        for(auto x : dd[node]){
            if(dist + x.se < dp[x.fi][id]){
                dp[x.fi][id] = dist + x.se;
                pq.push(mp(dp[x.fi][id], x.fi));
            }
        }
    }
}

struct line{
    ld ai;
    ld bi;
    ld lim;
};

ld intersect(line aa, line bb){
    return (bb.bi - aa.bi) / (aa.ai - bb.ai);
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 0 ; j <= k ; j ++ ){
            dp[i][j]=inf;
        }
    }
    int u, v, w;
    for(int i = 1; i <= m ; i ++ ){
        cin >> u >> v >> w;
        dd[u].push_back(mp(v, w));
        dd[v].push_back(mp(u, w));
    }
    dp[1][0]=0;
    line cur;
    line pa, pb;
    int g;
    for(int i = 0 ; i <= k ; i ++ ){
        if(i){
            vector<line> hull;
            for(int j = 1; j <= n; j ++ ){
                cur.ai = 2.0 * j;
                cur.bi = -dp[j][i - 1] - (ld)j * (ld)j;
                cur.lim = (ld)inf;
                while(hull.size() >= 2){
                    pa = hull[hull.size() - 2];
                    pb = hull[hull.size() - 1];
                    if(intersect(pa, pb) >= intersect(pa, cur)){
                        hull.pop_back();
                    }
                    else{
                        break;
                    }
                }
                if(!hull.empty()){
                    hull.back().lim = intersect(hull.back(), cur);
                }
                hull.push_back(cur);
            }
            g=0;
            for(int j = 1; j <= n; j ++ ){
                while(hull[g].lim < j){
                    g ++ ;
                }
                dp[j][i] = -hull[g].ai * 1ll * j - hull[g].bi + j * 1ll * j;
            }
        }
        layer(i);
    }
    for(int i = 1; i <= n; i ++ ){
        cout << dp[i][k] << " ";
    }
    cout << "\n";
    return 0;
}