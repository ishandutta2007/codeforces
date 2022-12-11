#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = 3003;
const int LOG = 13;
vector<int> T[N];
bool ok[N][N];
bool vis[N];
int n;

void dfs(int u, int start){
    vis[u] = true;
    ok[start][u] = true;
    for(auto p : T[u]){
        if(!vis[p]) dfs(p, start);
    }
}

void check(int u){
    for(int i = 0 ;i  < N; i ++ )
        vis[i] = false;
    dfs(u, u);
}

short anc[LOG][N][N];

void ff(int u){
    sort(T[u].begin(), T[u].end());
    for(int j = 1; j <= n; j ++ ){
        anc[0][u][j] = -1;
        if(u == j)
            continue;
        for(auto p : T[u]){
            if(ok[p][j]){
                anc[0][u][j] = p;
                break;
            }
        }
    }
}

int main(){
    fastIO;
    int m, q;
    cin >> n >> m >> q;
    int u, v;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
    }
    for(int i = 1; i <= n ; i ++ ) check(i);
    for(int i = 1; i <= n ; i ++ ) ff(i);
    for(int log = 1 ; log < LOG; log ++ ){
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= n; j ++ ){
                if(anc[log - 1][i][j] != -1){
                    anc[log][i][j] = anc[log-1][anc[log-1][i][j]][j];
                }
                else{
                    anc[log][i][j] = -1;
                }
            }
        }
    }
    int fnd, snd, ki;
    for(int i = 0 ; i < q; i ++ ){
        cin >> fnd >> snd >> ki;
        -- ki;
        if(!ok[fnd][snd] || anc[LOG-1][fnd][snd] != -1){
            cout << -1 << "\n";
            continue;
            
        }
        for(int j = 0 ; j < LOG; j ++ ){
            if(ki & (1 << j)){
                if(anc[j][fnd][snd] == -1){
                    fnd = -1;
                    break;
                }
                fnd = anc[j][fnd][snd];
            }
        }
        cout << fnd << "\n";
    }
    return 0;   
}