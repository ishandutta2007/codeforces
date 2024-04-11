#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld long double
mt19937 Rand(0);


const int inf = 1e9 + 7;
const int max_n = 44, N = 2e6 + 3;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int gr[max_n][max_n];
int n;

bool used[N];
bool was[max_n];

int dfs(int v, int k) {
    if (was[v]) return 0;
    was[v] = true;
    int res = 1;
    for (int to = 0; to < n; ++to) {
        if (gr[v][to] % k == 0) res += dfs(to, k);
    }
    return res;
}

void run() {
    cin >> n;
    vector<int> a(n);
    fill(used, used + N, false);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, int> qq;
    for (int i = 0; i < n; ++i)
        ++qq[a[i]];

    for (auto i : qq) {
        if (i.se >= n / 2) {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            gr[i][j] = abs(a[i] - a[j]);
            for (int q = 1; q * q <= gr[i][j]; ++q) {
                if (gr[i][j] % q != 0) continue;
                used[q] = true;
                used[gr[i][j] / q] = true;
            }
        }
    }
    for (int k = N - 1; k >= 1; --k) {
        if (!used[k]) continue;
        fill(was, was + max_n, 0);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            chkmax(mx, dfs(i, k));
        }
        if (mx >= n / 2) {
            cout << k << endl;
            break;
        }
    }
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        run();
    }
}