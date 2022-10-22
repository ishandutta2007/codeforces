#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <cassert>
#include <numeric>
#include <climits>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int root = 212, mod = 998244353, N = 2e5 + 12;

vector <int> ans;
void solve(int n) {
    if (n == 0) return;
    int sq = 0;
    while (sq * sq < n - 1) sq++;
    sq *= sq;
    solve(sq - n + 1);
    for (int i = sq - n + 1; i < n; i++) {
        ans[i] = n - 1 + (sq - n + 1) - i;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt --> 0) {
        int n; cin >> n;
        ans.assign(n, 0);
        solve(n);
        for (auto& x : ans) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}