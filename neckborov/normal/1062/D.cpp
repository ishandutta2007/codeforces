#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")

using namespace std;

typedef long double ld;
typedef long long ll;

const int N = 100100;

vector<int> g[N * 2];
int used[N * 2];
ll ans[N * 2];
int col;

void dfs(int v) {
    used[v] = col;
    for (int u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = -n; i <= n; ++i) {
        if (abs(i) <= 1) {
            continue;
        }
        for (int j = min(n / i, -n / i); j <= max(-n / i, n / i); ++j) {
            if (abs(j) <= 1) {
                continue;
            }
            g[i + N].push_back(i * j + N);
            g[i * j + N].push_back(i + N);
        }
    }
    for (int i = -n; i <= n; ++i) {
        if (!used[i + N]) {
            ++col;
            dfs(i + N);
        }
    }
    for (int i = -n; i <= n; ++i) {
        if (abs(i) <= 1) {
            continue;
        }
        for (int j : g[i + N]) {
            ans[used[i + N]] += abs((j - N) / i);
        }
    }
    ll kek = 0;
    for (int i = 1; i <= col; ++i) {
        kek = max(kek, ans[i]);
    }
    cout << kek;
    return 0;
}