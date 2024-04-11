#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

const long MOD = 1000000007;
string s0, t;
vector<long> p2;
vector<vector<long>> ps;

int calc(string w, int k, int c) {
    if (c > k) return 0;
//    cout << w << " " << c << "\n";
    int res = 0;
    if (c == 0) {
        int pp = s0.size() + 1;
        for (int z = 0; z <= pp; z++) {
            string ww;
            int j = z;
            bool ok = true;
            for (char cur : w) {
                if (j == pp - 1) {
                    ww += cur;
                } else {
                    if (cur != s0[j]) {
                        ok = false;
                        break;
                    }
                }
                j++;
                if (j == pp) j = 0;
            }
            if (ok) {
                if (ww.empty()) {
                    res += p2[k];
                    res %= MOD;
                } else {
                    res += calc(ww, k, 1);
                    res %= MOD;
                }
            }
        }
    } else {
        if (w.size() == 1) {
            int cc = w[0] - 'a';
            int s = ps[cc][k] - ps[cc][c - 1] * p2[k + 1 - c] % MOD;
            s %= MOD;
            res += s;
            res %= MOD;
        } else {
            for (int z = 0; z < 2; z++) {
                bool ok = true;
                for (int i = z; i < w.size(); i += 2) {
                    if (w[i] != t[c - 1]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    string ww;
                    for (int i = 1 - z; i < w.size(); i += 2) {
                        ww += w[i];
                    }
                    res += calc(ww, k, c + 1);
                    res %= MOD;
                }
            }
        }
    }
    if (res < 0) res += MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    cin >> s0 >> t;
    p2.resize(n + 1);
    p2[0] = 1;
    for (int i = 1; i < p2.size(); i++) p2[i] = p2[i - 1] * 2 % MOD;
    ps.assign(26, vector<long>(n + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            ps[j][i] = ps[j][i - 1] * 2 + (t[i - 1] - 'a' == j);
            ps[j][i] %= MOD;
        }
    }
    while (q--) {
        int k;
        cin >> k;
        string w;
        cin >> w;
        cout << calc(w, k, 0) << "\n";
    }

    return 0;
}