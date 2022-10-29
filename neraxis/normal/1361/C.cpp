#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 1200005;

int a[N], n;
bool check[N];
vector<int> ans;
vector<int> v[N];

void dfs(int u, int k) {
    check[u] = 1;
    int t = u / 2;
    int nx = 4 * t + 1 - u;
    // cout << u << ' ' << nx << ' ' << k << endl;
    if (!check[nx]) dfs(nx, k);
    else {
        int foo = a[u] % (1 << k);
        int id = -1;
        while (!v[foo].empty()) {
            int t = v[foo].back();
            v[foo].pop_back();
            if (check[t]) continue;
            dfs(t, k);
        }
    }
    ans.push_back(u);
}

void solve(int k) {
    memset(check, 0, sizeof(check));
    ans.clear();
    int foo = (1 << k);
    for (int i = 0; i < N; i++) v[i].clear();
    for (int i = 0; i < 2 * n; i++) v[a[i] % foo].pb(i);
    dfs(0, k);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < 2 * n; i++) cin >> a[i];
    for (int rep = 20; rep >= 0; rep--) {
        solve(rep);
        if (ans.size() == 2 * n) {
            bool ok = 1;
            for (int i = 1; i < ans.size(); i += 2) {
                if ((a[ans[i]] ^ a[ans[(i + 1) % (2 * n)]]) % (1 << rep) != 0) ok = 0;
            }
            if (ok == 0) continue;
            cout << rep << '\n';
            for (int e : ans) cout << e + 1 << ' ';
            return 0;
        }
    } 
    return 0;
}