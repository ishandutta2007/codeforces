#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int binpow(int a, ll b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int mid = binpow(a, b / 2);
    return mul(mid, mid);
}

vector<vector<int>> matrix_mul(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> res(a.size(), vector<int>(b[0].size()));
    range(i, a.size()) {
        range(j, b[0].size()) {
            res[i][j] = 0;
            range(p, b.size()) {
                res[i][j] = add(res[i][j], mul(a[i][p], b[p][j]));
            }
        }
    }
    return res;
}

vector<vector<int>> binpow_matrix(vector<vector<int>> &a, ll b) {
    if (b == 1) return a;
    if (b % 2) {
        return matrix_mul(a, binpow_matrix(a, b - 1));
    }
    auto mid = binpow_matrix(a, b / 2);
    return matrix_mul(mid, mid);
}

void solve() {
    int n, m, L, R;
    cin >> n >> m >> L >> R;
    if (n % 2 && m % 2) {
        cout << binpow((R - L + 1) % md, 1ll * n * m) % md << "\n";
        return;
    }
    int k = (R / 2 - (L - 1) / 2);
    int t = ((R - L + 1) - k);
    k %= md;
    t %= md;
    vector<vector<int>> a = {
            {k, t},
            {t, k}
    };

    auto res = binpow_matrix(a, 1ll * n * m);
    cout << res[0][0] % md;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}