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
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 2e7;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};
int cnt[maxN];

int n;
vector<int> a;

int solve2(int bit) {
    int bit1 = 1 << bit;
    int bit2 = 1 << (bit + 1);
    vector<int> b(n);
    range(i,n) b[i] = a[i] % bit2;
    sort(all(b));
    ll ans = 0;
    int bit3= bit2 + bit1;
    range(r, n) {
        int l = lower_bound(all(b), bit3 - b[r]) - b.begin();
        ans += r - min(r, l);
    }
    range(i, n) {
        int r1 = lower_bound(all(b), bit2 - b[i]) - b.begin();
        int l1 = lower_bound(all(b), bit1 - b[i]) - b.begin();
        r1 = min(r1, i);
        l1 = min(l1, r1);
        ans += r1 - l1;
    }
    return (ans % 2);
}

void solve() {
    cin >> n;
    a.resize(n);
    range(i,n) cin >> a[i];
    int ans = 0;
    range(b, 30) {
        if (solve2(b)) ans += (1 << b);
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