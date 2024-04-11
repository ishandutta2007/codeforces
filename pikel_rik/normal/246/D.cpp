#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 1;

int n, m;
vi g[N], color[N];

int c[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        color[c[i]].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if (c[u] == c[v]) continue;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vi cnt(N, -1);

    for (int i = 1; i <= N; i++) {
        if (color[i].empty()) continue;
        set<int> s;

        for (int &x : color[i]) {
            for (int &num : g[x]) {
                s.insert(c[num]);
            }
        }
        cnt[i] = s.size();
    }

    int best = -1, best_val = INT_MIN;
    for (int i = 1; i <= N; i++) {
        if (cnt[i] > best_val) {
            best_val = cnt[i];
            best = i;
        }
    }

    cout << best << "\n";
    return 0;
}