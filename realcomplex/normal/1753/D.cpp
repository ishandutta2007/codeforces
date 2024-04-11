#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<vector<char>> conf;

bool match(int i1, int j1, int i2, int j2){
    if(j1 == j2){
        if(i1 > i2) swap(i1, i2);
        if(conf[i1][j1] == 'U' && conf[i2][j2] == 'D') return true;
        else return false;
    }
    else if(i1 == i2){
        if(j1 > j2) swap(j1, j2);
        if(conf[i1][j1] == 'L' && conf[i2][j2] == 'R') return true;
        else return false;
    }
    else{
        return false;
    }
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    ll pp, qq;
    cin >> pp >> qq;
    vector<vector<ll>> dist(n + 2);
    conf.resize(n + 2);
    vector<vector<bool>> vis(n + 2);
    for(int i = 0 ; i <= n + 1; i ++ ){
        dist[i].resize(m + 2, (ll)1e18);
        conf[i].resize(m + 2, '#');
        vis[i].resize(m + 2, false);
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m ; j ++ ){
            cin >> conf[i][j];
        }
    }
    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m ; j ++ ){
            if(conf[i][j] == '.'){
                pq.push(mp(0ll, mp(i, j)));
                dist[i][j] = 0ll;
            }
        }
    }
    ll res;
    pii F;
    int ii, jj;
    int ni, nj;
    ll G;
    while(!pq.empty()){
        res = pq.top().fi;
        F = pq.top().se;
        pq.pop();
        if(vis[F.fi][F.se]) continue;
        vis[F.fi][F.se] = true;
        ii = F.fi;
        jj = F.se;
        for(int p = -2; p <= +2; p ++ ){
            for(int q = -2; q <= +2; q ++ ){
                if(abs(p) + abs(q) == 2){
                    ni = ii + p;
                    nj = jj + q;
                    if(ni >= 1 && ni <= n && nj >= 1 && nj <= m){
                        if(abs(p) == 1){
                            G = pp;
                            if(match(ii + p, jj, ni, nj) || match(ii, jj + q, ni, nj)){
                                if(dist[ni][nj] > dist[ii][jj] + G){
                                    dist[ni][nj] = dist[ii][jj] + G;
                                    pq.push(mp(dist[ni][nj], mp(ni, nj)));
                                }
                            }
                        }
                        else{

                            G = qq;
                            if(match(ii + p/2, jj + q/2, ni, nj)){
                                if(dist[ni][nj] > dist[ii][jj] + G){
                                    dist[ni][nj] = dist[ii][jj] + G;
                                    pq.push(mp(dist[ni][nj], mp(ni, nj)));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    ll low = (ll)1e18;
    for(int i = 1; i <= n ; i ++ ){
        for(int j = 1; j <= m; j ++ ){
            low = min(low, dist[i][j] + dist[i][j + 1]);
            low = min(low, dist[i][j] + dist[i + 1][j]);
        }
    }
    if(low == (ll)1e18){
        cout << -1 << "\n";
        return 0;
    }
    cout << low << "\n";
}