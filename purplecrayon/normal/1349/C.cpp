#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

int n, m, nq;
ll d[MAXN][MAXN];
string g[MAXN];

void solve(){
    cin >> n >> m >> nq;
    for (int i = 0; i < n; i++) cin >> g[i];
//    cerr << n << ' ' << m << '\n';
//    for (int i = 0; i < n; i++) cerr << g[i] << '\n';
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
        d[i][j]=INF;
        bool bad=1;
        for (int k = 0; k < 4; k++){
            int ni=i+hA[k], nj=j+kA[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (g[ni][nj] == g[i][j]) bad=0;
        }
        if (!bad) q.push({i, j}), d[i][j]=0;
    }
    while (sz(q)){
    	auto c = q.front(); q.pop();
    	int i=c.first, j=c.second;
        for (int k = 0; k < 4; k++){
            int ni=i+hA[k], nj=j+kA[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || d[ni][nj] < INF) continue;
            d[ni][nj] = d[i][j]+1, q.push({ni, nj});
        }
    }
    while (nq--){
        int i, j; ll p; cin >> i >> j >> p, --i, --j, --p;
        cerr << p-d[i][j]+1 << "\n";
        if (d[i][j] > p) cout << g[i][j] << '\n';
        else if ((p-d[i][j]+1)&1) cout << char(g[i][j]^'0'^'1') << '\n';
        else cout << g[i][j] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}