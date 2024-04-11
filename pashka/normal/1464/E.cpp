#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

vector<vector<int>> g;
vector<int> gr;

void dfs(int x) {
    if (gr[x] != -1) return;
    vector<bool> z((int)g[x].size() + 1);
    for (int y : g[x]) {
        dfs(y);
        if (gr[y] < (int)z.size()) z[gr[y]] = true;
    }
    gr[x] = 0;
    while (z[gr[x]]) gr[x]++;
}

const long MOD = 998244353;

long sum(long a, long b) {
    long res = (a + b) % MOD;
    if (res < 0) res += MOD;
    return res;
}
long mult(long a, long b) {
    long res = a * b % MOD;
    if (res < 0) res += MOD;
    return res;
}

long power(long a, long b) {
    long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mult(res, a);
        }
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

long inv(long a) {
    return power(a, MOD - 2);
}


int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }
    gr.assign(n, -1);
    for (int i = 0; i < n; i++) {
        dfs(i);
    }
    int mx = 512;
//    for (int i = 0; i < n; i++) {
//        mx = max(mx, gr[i]);
//    }
//    while (mx & (mx + 1)) mx++;
//    mx++;
    vector<int> cnt(mx);
    cerr << mx << "\n";
    for (int i = 0; i < n; i++) {
        cnt[gr[i]]++;
    }
    vector<vector<int>> a(mx, vector<int>(mx + 1));
    for (int i = 0; i < mx; i++) {
        for (int j = 0; j < mx; j++) {
            a[i][j] = cnt[i ^ j];
        }
        a[i][i] -= (n + 1);
        a[i][mx] = -(i != 0);
        for (int j = 0; j <= mx; j++) {
            a[i][j] %= MOD;
            if (a[i][j] < 0) a[i][j] += MOD;
        }
    }
//    for (int i = 0; i < mx; i++) {
//        for (int j = 0; j <= mx; j++) {
//            cout << a[i][j] << " ";
//        }
//        cout << "\n";
//    }
    for (int i = 0; i < mx; i++) {
        int j = i;
        while (j < mx && a[j][i] == 0) j++;
        if (j == mx) {
            while (1) {
            }
        }
        swap(a[i], a[j]);
        int k = inv(a[i][i]);
        for (int j = 0; j <= mx; j++) {
            a[i][j] = mult(a[i][j], k);
        }
        for (int t = 0; t < mx; t++) {
            if (t == i) continue;
            k = a[t][i];
            for (int j = 0; j <= mx; j++) {
                a[t][j] = sum(a[t][j], mult(a[i][j], -k));
            }
        }
    }
//    for (int i = 0; i < mx; i++) {
//        for (int j = 0; j <= mx; j++) {
//            cout << a[i][j] << " ";
//        }
//        cout << "\n";
//    }
    int st = 0;
//    for (int x : gr) st ^= x;
    cout << a[st][mx] << "\n";
    return 0;
}