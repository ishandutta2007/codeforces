#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 6e5 + 100;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> c(n);
    range(i, n) {
        cin >> c[i];
        c[i]--;
    }
    vector<int> to(n + 1);
    range(i, n) {
        if (i < l) to[c[i]]++;
        else to[c[i]]--;
    }
    vector<int> vec;
    int result = 0;
    range(i, n) {
        if (to[i] % 2 != 0) {
            int d = to[i] % 2;
            to[i] -= d;
            if (!vec.empty() && vec.back() != d) {
                vec.pop_back();
            } else {
                vec.push_back(d);
                result++;
            }
        }
    }
    range(i, n) {
        while (to[i] < 0 && !vec.empty() && vec.back() == 1) {
            to[i]++;
            vec.pop_back();
        }
        while(to[i] > 0 && !vec.empty() && vec.back() == -1) {
            to[i]--;
            vec.pop_back();
        }
    }
    range(i, n) {
        result += abs(to[i]) / 2;
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}