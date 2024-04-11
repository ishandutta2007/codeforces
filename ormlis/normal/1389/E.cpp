#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <set>
#include <map>
#include <random>
#include <chrono>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
using namespace std;

const int INFi = 1e9;
const ll INF = 1e18;

void solve() {
    // (x + y * d) % w == (y + x * d) % w
    // x + y * d == y + x * d
    // x * (d-1) == y * (d-1)
    // x, y < min(d, m)
    // d % w
    // d /= gcd(d, w)
    // w /= gcd(d, w)
    // w....
    ll m, d, w;
    cin >> m >> d >> w;
    d--;
    ll kek = d % w;
    ll kek2 = w / __gcd(w, kek);
    ll o = min(d+1, m);
    ll cycles = o / kek2;
    ll cn1 = o % kek2;
    ll cn2 = kek2 - cn1;
    // C(cycles, 2) * cn1
    ll ans1 = cycles * (cycles + 1) / 2 * cn1;
    ll ans2 = (cycles - 1) * cycles / 2 * cn2;
    cout << ans1 + ans2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}