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
const int maxN = 1e5 + 100;
const int md = 1e9 + 123;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> rc(n);
    range(i, n) cin >> rc[i].first;
    range(i, n) cin >> rc[i].second;
    rc.emplace_back(1, 1);
    sort(all(rc));
    ll answer = 0;
    for(int i = 1; i <= n; ++i) {
        ll d1 = rc[i].first - rc[i].second;
        ll d2 = rc[i - 1].first - rc[i - 1].second;
        if (d1 == d2) {
            if (d2 % 2 == 0) {
                answer += rc[i].first - rc[i - 1].first;
            }
            continue;
        }
        answer += (d1 - d2) / 2;
        if ((d1 - d2) % 2 && d2 % 2) answer++;
    }
    cout << answer << '\n';
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