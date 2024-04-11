#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>
#include <bitset>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < (n); ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int maxW = 5e6 + 5;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

using Bitset = bitset<maxW>;
int n;
int a[maxN];
int order[maxN];

void check1() {
    vector<int> kek;
    for (int i = 2; i <= n; ++i) {
        if (a[i] == a[i - 1]) kek.push_back(i);
    }
    sort(all(kek));
    if (kek.size() <= 1) return;
    if (kek.front() + 1 >= kek.back()) return;
    cout << "YES\n";
    cout << order[kek.front() - 1] << ' ' << order[kek.back() - 1] << ' ' << order[kek.front()]
         << ' ' << order[kek.back()];
    exit(0);
}

int was[maxW];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    iota(order + 1, order + n + 1, 1);
    sort(order + 1, order + n + 1, [&](const int i, const int j) {
        return a[i] < a[j];
    });
    sort(a + 1, a + n + 1);
    check1();
    int ans = -1;
    for(int i = 2; i <= n; ++i) {
        if (a[i] == a[i - 1]) continue;
        for(int j = i - 1; j >= 1; --j) {
            int x = a[i] - a[j];
            if (was[x] == 0) {
                was[x] = i;
            }
            if (was[x] == j || was[x] == i) continue;
            ans = x;
            break;
        }
        if (ans != -1) break;
    }
    if (ans == -1) {
        cout << "NO\n";
        return;
    }
    int l = 1;
    vector<pair<int, int>> answer;
    for (int i = 2; i <= n; ++i) {
        while (l + 1 < i && a[i] - a[l] > ans) {
            l++;
        }
        if (i > l && a[i] - a[l] == ans) {
            answer.emplace_back(order[l], order[i]);
            l = i + 1;
        }
    }
    cout << "YES\n";
    cout << answer[0].first << ' ' << answer[1].second << ' ' << answer[1].first << ' '
         << answer[0].second << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}