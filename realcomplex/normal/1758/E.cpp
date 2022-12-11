#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)4e5 + 10;
const int MOD = (int)1e9 + 7;
vector<pii> T[N];
int h;
int dep[N];
int sum[N];

void add_edge(int u, int v, int w){
    T[u].push_back(mp(v, w));
    T[v].push_back(mp(u, w));
}

bool trash;

void dfs(int node){
    for(auto p : T[node]){
        if(dep[p.fi] == -1){
            dep[p.fi] = (dep[node] ^ 1);
            if(dep[node] == 0){
                sum[p.fi] = (sum[node] + p.se) % h;
            }
            else{
                sum[p.fi] = (sum[node] - p.se + h) % h;
            }
            dfs(p.fi);
        }
        else{
            if(dep[node] == 0){
                if((sum[node] + p.se) % h != sum[p.fi]){
                    trash = true;
                }
            }
            else{
                if((sum[node] - p.se + h) % h != sum[p.fi]){
                    trash = true;
                }
            }
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m >> h;
    for(int i = 1; i <= n + m; i ++ ){
        T[i].clear();
        dep[i] = -1;
        sum[i] = 0;
    }
    int x;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j ++ ){
            cin >> x;
            if(x != -1){
                add_edge(i, n + j, x);
            }
        }
    }
    trash = false;
    int cnt = 0;
    for(int i = 1; i <= n + m ; i ++ ){
        if(dep[i] == -1){
            dep[i] = 0;
            cnt ++ ;
            dfs(i);
        }
    }

    if(trash){
        cout << "0\n";
        return;
    }
    int res = 1;
    for(int i = 1; i < cnt; i ++ ){
        res = (res * 1ll * h) % MOD;
    }
    cout << res << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}