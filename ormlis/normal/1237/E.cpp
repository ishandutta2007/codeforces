#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 1e9;
const int maxN = 400000 + 2000;
const int md = 998244353;
const int md2 = 1e9 + 7;

// double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int solve(int l, int r, int c) {
    if (l > r) {
        return 1;
    }
    int mid = (r + l) / 2;
    int res = 0;
    if (mid % 2 == c) res += 1ll * solve(l, mid - 1, (c + 1) % 2) * solve(mid + 1, r, c) % md;
    if ((r - l + 1) % 2 == 0) {
        int mid2 = (r + l + 1) / 2;
        if (mid2 % 2 == c) res += 1ll * solve(l, mid2 - 1, (c + 1) % 2) * solve(mid2 + 1, r, c) % md;
    }
    return res % md;
}

void solve() {
    int n; cin >> n;
    cout << (solve(1, n, 0) + solve(1, n, 1)) % md;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}