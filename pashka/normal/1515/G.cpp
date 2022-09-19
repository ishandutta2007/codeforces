#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

vector<vector<pair<int, long>>> g;
vector<vector<int>> gr;
vector<int> z;
vector<long> pd;
vector<int> c;
int cc;
long dd;

long gcd(long a, long b) {
    while (b != 0) {
        long c = a % b;
        a = b;
        b = c;
    }
    return a;
}

void dfs(int x, long d) {
    if (z[x]) return;
    c[x] = cc;
    z[x] = 1;
    pd[x] = d;
    for (auto e : g[x]) {
        dfs(e.first, d + e.second);
    }
}

vector<int> p;

void dfs2(int x) {
    if (z[x]) return;
    z[x] = 1;
    for (int y : gr[x]) {
        dfs2(y);
    }
    p.push_back(x);
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    g.resize(n);
    gr.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--;
        b--;
        g[a].push_back({b, l});
        gr[b].push_back(a);
//        g[b].push_back({a, l});
    }
    z.resize(n);
    for (int i = 0; i < n; i++) {
        dfs2(i);
    }
    z.assign(n, 0);
    vector<long> d(n);
    pd.resize(n);
    c.resize(n);
    reverse(p.begin(), p.end());
    for (int i : p) {
        if (z[i] == 0) {
            dfs(i, 0);
            cc++;
        }
    }
    for (int x = 0; x < n; x++) {
        for (auto e : g[x]) {
            if (c[e.first] == c[x]) {
                long k = abs(e.second + pd[x] - pd[e.first]);
                d[c[x]] = gcd(d[c[x]], k);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int v, s, t;
        cin >> v >> s >> t;
        v--;
        long k = gcd(d[c[v]], t);
        if (k > 0 && s % k == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}