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
    string s;
    cin >> s;
    vector<bool> was(26);
    int n = s.size();
    vector<bool> last(n, false);
    for (int i = n - 1; i >= 0; --i) {
        last[i] = (!was[s[i] - 'a']);
        was[s[i] - 'a'] = true;
    }
    int cnt = 0;
    range(i, 26) {
        cnt += was[i];
        was[i] = false;
    }
    int l = 0, r = 0;
    set<pair<char, int>> se;
    range(_, cnt) {
        while (r < n) {
            if (r > l && !was[s[r - 1] - 'a'] && last[r - 1]) break;
            se.insert({s[r], -r});
            r++;
        }
        bool f = false;
        while(!f) {
            int i = -se.rbegin()->second;
            if (was[s[i] - 'a']) {
                se.erase({s[i], -i});
                continue;
            }
            while (l <= i) {
                if (se.count({s[l], -l})) se.erase({s[l], -l});
                l++;
            }
            was[s[i] - 'a'] = true;
            cout << s[i];
            f = true;
        }
    }
    cout << '\n';
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