#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-8
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

int n, k;
ll dp[70][70];
vector<vector<pair<int, char>>> ops;

bool check_for(int l, int r, int x, int y) {
    for (auto op : ops[x]) {
        int v = op.first;

        switch (op.second) {
            case '<':
                if (!(l <= v && v <= r)) {
                    return false;
                }
                break;
            case '[':
                if (!(l <= v && v <= r) && v != x && v != y) {
                    return false;
                }
                break;
            case '=':
                if (v != x && v != y) {
                    return false;
                }
                break;
        }
    }

    return true;
}

//   [l; r],   x  y,   ?
bool check(int l, int r, int x, int y) {
    if (x < 0 || x >= 2 * n || y < 0 || y >= 2 * n) {
        return false;
    }

    return check_for(l, r, x, y) && check_for(l, r, y, x);
}

ll solve(int l, int r) {
    if (l < 0 || r >= 2 * n || l > r) {
        return 0;
    }

    if (dp[l][r] != -1) {
        return dp[l][r];
    }

    ll result = 0;
    if (check(l, r, l - 1, r + 1)) {
        result += solve(l - 1, r + 1);
    }
    if (check(l, r, l - 2, l - 1)) {
        result += solve(l - 2, r);
    }
    if (check(l, r, r + 1, r + 2)) {
        result += solve(l, r + 2);
    }

    dp[l][r] = result;

    return result;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k;
    ops.resize(2 * n);
    for (int i = 0; i < k; i++) {
        int x, y;
        string op;
        cin >> x >> op >> y;

        if (op == ">") {
            op = "<";
            swap(x, y);
        } else if (op == ">=") {
            op = "<=";
            swap(x, y);
        }

        x--;
        y--;
        ops[x].push_back(mp(y, op.size() == 1 ? op[0] : '['));
    }

    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            dp[i][j] = -1;
        }
    }

    dp[0][2 * n - 1] = 1;

    ll ans = 0;

    for (int i = 0; i < 2 * n - 1; i++) {
        if (check(1, 0, i, i + 1)) {
            ans += solve(i, i + 1);
        }
    }

    cout << ans << "\n";

    return 0;
}