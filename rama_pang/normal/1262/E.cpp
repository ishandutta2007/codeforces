#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void solve() {

    int N, M; cin >> N >> M;
    vector<vector<lint>> grid(N, vector<lint>(M, 0));
    vector<vector<lint>> pref2(N, vector<lint>(M, 0));
    vector<vector<lint>> tmp(N, vector<lint>(M, 0));
    vector<vector<lint>> pref(N, vector<lint>(M, 0));

    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == 'X') {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            pref[i][j] = grid[i][j];
            if (i > 0) pref[i][j] += pref[i - 1][j];
            if (j > 0) pref[i][j] += pref[i][j - 1];
            if (i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];
        }
    }

    auto get = [&](int r1, int c1, int r2, int c2, const vector<vector<lint>> &p) {
        lint ans = 0;
        ans += p[r2][c2];
        if (r1 > 0) ans -= p[r1 -1][c2];
        if (c1 > 0) ans -= p[r2][c1 - 1];
        if (r1 > 0 && c1 > 0) ans += p[r1 - 1][c1 - 1];
        assert(ans >= 0);
        return ans;
    };

    auto inside = [&] (int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < M;
    };

    auto check = [&](int x) {
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                tmp[i][j] = 0;
                if (!inside(i - x, j - x)) continue;
                if (!inside(i + x, j + x)) continue;
                if (!inside(i - x, j + x)) continue;
                if (!inside(i + x, j - x)) continue;
                
                lint side = 2 * x + 1;
                side *= side;
                if (get(i - x, j - x, i + x, j + x, pref) == side) {
                    tmp[i][j] = 1;
                    // cout << i << " " << j << " " << x << "<<<\n";
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                pref2[i][j] = 0;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                pref2[i][j] = tmp[i][j];
                if (i > 0) pref2[i][j] += pref2[i - 1][j];
                if (j > 0) pref2[i][j] += pref2[i][j - 1];
                if (i > 0 && j > 0) pref2[i][j] -= pref2[i - 1][j - 1];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 0) continue;
                if (get(max(i - x, 0), max(j - x, 0), min(i + x, N - 1), min(j + x, M - 1), pref2) > 0) {
                    // cout << i << " " << j << " " << get(max(0, i - x), max(j - x, 0), min(i + x, N - 1), min(j + x, M - 1), pref2) << "chchs\n";
                    continue;
                }
                // cout << i << " " << j << " " << x << "\n";
                return false;
            }
        }
        // cout << "SUCCESS " << x << "\n";
        return true;
    };

    lint le = 0, ri = max(N, M), ans = 0;
    while (le <= ri) {
        lint mid = (le + ri) / 2;
        if (check(mid)) {
            ans = mid;
            le = mid + 1;
        } else {
            ri = mid - 1;
        }
    }

    check(ans);
    cout << ans << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmp[i][j] == 1) {
                cout << 'X';
            } else {
                cout << '.';
            }
        }
        cout << "\n";
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int TESTCASE;
    // cin >> TESTCASE;
    TESTCASE = 1;
    while (TESTCASE--) {
        solve();
    }
}