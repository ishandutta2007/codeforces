#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const int N = 102;

void run() {
    int n; cin >> n;
    vector<int> b(n);
    for (auto& i : b) {
        cin >> i;
    }
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] > i+1) k = i+1;
    }

    cout << k << '\n';

    vector g(n+2, vector<int>());
    for (int i = 0; i < n; ++i) {
        g[b[i]].push_back(i+1);
    }
    for (int i = 0; i < n+2; ++i) {
        sort(all(g[i]), [&g](int u, int v) { return g[u].size() < g[v].size(); });
    }

    int st = (g[0].size() ? 0 : n+1);

    while (g[st].size()) {
        for (auto i : g[st]) {
            cout << i << " ";
        }
        st = g[st].back();
    }
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