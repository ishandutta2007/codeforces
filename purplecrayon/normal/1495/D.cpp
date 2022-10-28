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
const int MAXN = 4e2+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 1e6+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, m;
int d[MAXN][MAXN], cnt_short[MAXN];
vector<int> adj[MAXN];

void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j]=(i==j?0:INF);

    while (m--){
        int a, b; cin >> a >> b, --a, --b;
        d[a][b]=d[b][a]=1;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

    auto get = [&](int a, int b) -> ll {
        memset(cnt_short, 0, sizeof(cnt_short));
        for (int i = 0; i < n; i++) if (d[a][i]+d[i][b] == d[a][b]) {
            cnt_short[d[a][i]]++;
        }
        for (int i = 0; i < n; i++) if (cnt_short[i] > 1) return 0;

        ll ans=1;
        for (int i = 0; i < n; i++) if (d[a][i]+d[b][i] != d[a][b]) {
            int cur=0;
            for (auto j : adj[i]) if (d[a][j]==d[a][i]-1 && d[j][b]==d[i][b]-1)
                cur++;
            ans *= cur;
            ans %= MOD;
        }
        return ans;
    };

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << get(i, j) << ' ';
        }
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}