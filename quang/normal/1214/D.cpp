#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const int MOD1 = (int)1e9 + 7;
const int MOD2 = (int)1e9 + 9;

inline int add(int u, int v, int MOD) {
    return (u += v) >= MOD ? u - MOD : u;
}
 
inline int sub(int u, int v, int MOD) {
    return (u -= v) < 0 ? u + MOD : u;
}
 
inline int mul(int u, int v, int MOD) {
    return (long long)u * v % MOD;
}
 

int n, m;
string s[N];
vector<vector<int>> f1, f2, g1, g2;

bool inside(int u, int v) {
    return u >= 0 && u < n && v >= 0 && v < m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    f1.resize(n, vector<int>(m, 0));
    g1.resize(n, vector<int>(m, 0));
    f2.resize(n, vector<int>(m, 0));
    g2.resize(n, vector<int>(m, 0));
    vector<vector<int>> used(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                f1[i][j] = f2[i][j] = 1;
                used[i][j] = 1;
            }
            else {
                if (s[i][j] == '#') continue;
                if (inside(i - 1, j)) {
                    f1[i][j] = add(f1[i][j], f1[i - 1][j], MOD1);
                    f2[i][j] = add(f2[i][j], f2[i - 1][j], MOD2);
                    used[i][j] |= used[i - 1][j];
                }
                if (inside(i, j - 1)) {
                    f1[i][j] = add(f1[i][j], f1[i][j - 1], MOD1);
                    f2[i][j] = add(f2[i][j], f2[i][j - 1], MOD2);
                    used[i][j] |= used[i][j - 1];
                }
            }
        }
    }

    if (!used[n - 1][m - 1]) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 && j == m - 1) g1[i][j] = g2[i][j] = 1;
            else {
                if (s[i][j] == '#') continue;
                if (inside(i + 1, j)) {
                    g1[i][j] = add(g1[i][j], g1[i + 1][j], MOD1);
                    g2[i][j] = add(g2[i][j], g2[i + 1][j], MOD2);
                }
                if (inside(i, j + 1)) {
                    g1[i][j] = add(g1[i][j], g1[i][j + 1], MOD1);
                    g2[i][j] = add(g2[i][j], g2[i][j + 1], MOD2);
                }
            }
        }
    }

    int found = 0;
    int tot1 = g1[0][0], tot2 = g2[0][0];
    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < m && !found; j++) {
            if (s[i][j] == '#') continue;
            if (i == 0 && j == 0) continue;
            if (i == n - 1 && j == m - 1) continue;
            int now1 = mul(f1[i][j], g1[i][j], MOD1);
            int now2 = mul(f2[i][j], g2[i][j], MOD2);
            if (now1 == tot1 && now2 == tot2) {
                found = 1;
            }
        }   
    }
    if (found) cout << 1 << endl;
    else cout << 2 << endl;
    return 0;
}