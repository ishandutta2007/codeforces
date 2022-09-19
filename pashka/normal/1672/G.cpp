#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

vector<vector<int>> g;

const long MOD = 998244353;

vector<bool> z;
vector<int> d;
int s1, se, sv;

void dfs(int x) {
    if (z[x]) return;
    z[x] = true;
    sv++;
    if (d[x] == 1) s1++;
    for (int y: g[x]) {
        se++;
        dfs(y);
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    g.resize(n + m);
    d.resize(n + m);
    int c = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '?') {
                g[i].push_back(n + j);
                g[n + j].push_back(i);
                c++;
            } else {
                if (s[j] == '1') {
                    d[i] ^= 1;
                    d[n + j] ^= 1;
                }
            }
        }
    }
    vector<long> p2(n * m + 1);
    p2[0] = 1;
    for (int i = 0; i < n * m; i++) {
        p2[i + 1] = (p2[i] * 2) % MOD;
    }
    if (n % 2 == 0 && m % 2 == 0) {
        cout << p2[c] << "\n";
        return 0;
    }
    if (n % 2 == 0 && m % 2 == 1) {
        long res = 0;
        for (int t = 0; t < 2; t++) {
            long s = 1;
            for (int i = 0; i < n; i++) {
                int x = d[i] ^t;
                if (x == 1 && g[i].size() == 0) {
                    s = 0;
                }
                if (g[i].size() > 0) {
                    s *= p2[g[i].size() - 1];
                    s %= MOD;
                }
            }
            res += s;
            res %= MOD;
        }
        cout << res << "\n";
        return 0;
    }
    if (n % 2 == 1 && m % 2 == 0) {
        long res = 0;
        for (int t = 0; t < 2; t++) {
            long s = 1;
            for (int j = 0; j < m; j++) {
                int x = d[n + j] ^t;
                if (x == 1 && g[n + j].size() == 0) {
                    s = 0;
                }
                if (g[n + j].size() > 0) {
                    s *= p2[g[n + j].size() - 1];
                    s %= MOD;
                }
            }
            res += s;
            res %= MOD;
        }
        cout << res << "\n";
        return 0;
    }
    long res = 0;
    for (int t = 0; t < 2; t++) {
        long s = 1;
        z.assign(n + m, false);
        for (int i = 0; i < n + m; i++) {
            if (z[i]) continue;
            s1 = 0;
            sv = 0;
            se = 0;
            dfs(i);
            if (t == 1) s1 = sv - s1;
            se /= 2;
            if (s1 % 2 == 1) {
                s = 0;
                break;
            }
            int x = se - (sv - 1);
            s *= p2[x];
            s %= MOD;
        }
        res += s;
        res %= MOD;
    }
    cout << res << "\n";

    return 0;
}