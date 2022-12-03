#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast", "no-stack-protector")
//#pragma GCC target("sse4", "avx", "popcnt", "lzcnt", "sse3", "sse4.1", "sse4.2", "sse2", "tune=native")
//#pragma GCC optimize ("unroll-loops")

using namespace std;

typedef long double old;
typedef long long ll;

const int N = 501;

vector<int> g[N];
int h[N];
int diam;

void dfs(int v, int par = -1) {
    diam = max(diam, h[v]);
    for (int u : g[v]) {
        if (u != par) {
            h[u] = h[v] + 1;
            dfs(u, v);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    int kek = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i].first != 1) {
            kek = i;
            break;
        }
    }
    if (kek == -1) {
        cout << "NO";
        return 0;
    }
    kek = max(kek, 2);
    g[a[0].second].push_back(a[kek].second);
    g[a[kek].second].push_back(a[0].second);
    g[a[1].second].push_back(a[n - 1].second);
    g[a[n - 1].second].push_back(a[1].second);
    for (int i = kek; i + 1 < n; ++i) {
        g[a[i].second].push_back(a[i + 1].second);
        g[a[i + 1].second].push_back(a[i].second);
        a[i].first -= 2;
    }
    a[n - 1].first -= 2;
    for (int i = 2; i < kek; ++i) {
        bool f = true;
        for (int j = kek; j < n; ++j) {
            if (a[j].first > 0) {
                --a[j].first;
                f = false;
                g[a[i].second].push_back(a[j].second);
                g[a[j].second].push_back(a[i].second);
                break;
            }
        }
        if (f) {
            cout << "NO";
            return 0;
        }
    }
    h[1] = 1;
    dfs(1);
    int st = 1;
    for (int i = 1; i <= n; ++i) {
        if (!h[i]) {
            cout << "NO";
            return 0;
        }
        if (h[i] > h[st]) {
            st = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        h[i] = 0;
    }
    diam = 0;
    dfs(st);
    cout << "YES " << diam << '\n';
    int tt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j : g[i]) {
            if (i < j) {
                ++tt;
            }
        }
    }
    cout << tt << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j : g[i]) {
            if (i < j) {
                cout << i << ' ' << j << '\n';
            }
        }
    }
    return 0;
}