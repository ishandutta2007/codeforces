#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 3e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) {
        cin >> a[i];
        a[i]--;
    }
    range(i, n) if (a[i] % 2 != i % 2) {
            cout << "-1\n";
            return;
        }
    vector<int> ans;
    auto Do = [&] (int x) {
        assert(x % 2 == 1);
        ans.push_back(x);
        reverse(a.begin(), a.begin() + x);
    };
    for(; n > 1; n -= 2) {
        range(i, n) {
            if (a[i] == n - 1) {
                Do(i + 1);
                break;
            }
        }
        assert(a[0] == n - 1);
        range(i, n) {
            if (a[i] == n - 2) {
                Do(i);
                Do(i + 2);
                break;
            }
        }
        Do(3);
        assert(a[0] == n - 1 && a[1] == n - 2);
        Do(n);
    }
    cout << ans.size() << '\n';
    for(auto &x : ans) cout << x << ' ';
    cout << '\n';
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