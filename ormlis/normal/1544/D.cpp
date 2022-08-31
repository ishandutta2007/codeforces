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
typedef double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) {
        cin >> a[i];
        a[i]--;
    }
    vector<bool> us1(n);
    vector<bool> us2(n);
    vector<int> b(n, -1);
    vector<int> c(n, -1);
    range(i, n) {
        if (!us1[a[i]]) {
            us1[a[i]] = true;
            us2[i] = true;
            b[i] = a[i];
            c[a[i]] = i;
        }
    }
    vector<int> nus1, nus2;
    range(i, n) {
        if (!us1[i] && !us2[i]) {
            nus1.push_back(i);
            nus2.push_back(i);
        }
    }
    range(i, n) {
        if (!us1[i] && us2[i]) nus1.push_back(i);
        if (!us2[i] && us1[i]) nus2.push_back(i);
    }
    if (!nus1.empty()) {
        if (nus1.size() == 1 && nus1[0] == nus2[0]) {
            assert(nus1.size() == 1);
            int x = nus1[0];
            int y = c[a[x]];
            b[y] = x;
            b[x] = a[x];
        } else {
            rotate(nus2.begin(), nus2.begin() + 1, nus2.end());
            range(i, (int) nus1.size()) {
                assert(nus1[i] != nus2[i]);
                b[nus2[i]] = nus1[i];
            }
        }
    }
    int ans = 0;
    range(i, n) {
        if (a[i] == b[i]) ans++;
    }
    cout << ans << '\n';
    range(i, n) cout << b[i] + 1 << ' ';
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