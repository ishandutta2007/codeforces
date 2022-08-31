#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 80;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};
pair<ll, int> tree[2000020]; int arr[2000000];

pair<ll, int> get(int v, int l, int r, int L, int R) {
    if (l >= R || L >= r) {
        return {0, 0};
    }
    if (l <= L && R <= r) {
        return tree[v];
    }
    auto a = get(v * 2, l, r, L, (L + R) / 2);
    auto b = get(v * 2 + 1, l, r, (L + R) / 2, R);
    return {a.first + b.first, a.second + b.second};
}

void update(int v, int L, int R, int pos, int x) {
    if (R - L == 1) {
        tree[v] = {x, 1};
        return;
    }
    if (L <= pos && pos < (L + R) / 2) {
        update(v * 2, L, (L + R) / 2, pos, x);
    } else {
        update(v * 2 + 1, (L + R) / 2, R, pos, x);
    }
    tree[v] = {tree[v * 2].first + tree[v * 2 + 1].first, tree[v * 2].second + tree[v * 2 + 1].second};
}


void solve() {
    int n; cin >> n;
    vector<pair<int, int>> xv(n);
    range(i, n) cin >> xv[i].first;
    range(i, n) cin >> xv[i].second;
    sort(all(xv));
    range(i, n) arr[i] = (int)1e9-xv[i].first;
    vector<pair<int, int>> nxv(n);
    range(i, n) nxv[i] = {xv[i].second, i};
    range(i, n * 4) tree[i] = {0, 0};
    sort(all(nxv));
    ll ans = 0;
    range(i, n) {
        int v = nxv[i].first;
        int j = nxv[i].second;
        auto p = get(1, 0, j, 0, n);
        ans += p.first - (1ll * arr[j] * p.second);
        update(1, 0, n, j, arr[j]);
    }
    cout << ans;
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