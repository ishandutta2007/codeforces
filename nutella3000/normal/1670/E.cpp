#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;
const int N = 1 << 20, mod = 1e9 + 7;

int n;
vector<pii> gr[N];
int col[N];
int X = 1;

void dfs(int v, int pr = -1) {
    for (auto e : gr[v]) {
        auto [to, id] = e;
        if (to == pr) continue;
        if (col[v] >= n) {
            col[id+n] = X+n;
            col[to] = X;
        } else {
            col[id+n] = X;
            col[to] = X + n;
        }
        ++X;
        dfs(to, v);
    }
}

void run() {
    cin >> n; n = (1 << n); X = 1;
    for (int i = 0; i < n; ++i)
        gr[i].clear();

    for (int i = 0; i < n-1; ++i) {
        int v1, v2; cin >> v1 >> v2; --v1, --v2;
        gr[v1].eb(v2, i), gr[v2].eb(v1, i);
    }
    col[0] = n;
    dfs(0);
    cout << 1 << '\n';
    for (int i = 0; i < n; ++i)
        cout << col[i] << " ";
    cout << '\n';
    for (int i = n; i < 2*n-1; ++i)
        cout << col[i] << " ";
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}