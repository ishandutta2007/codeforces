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
const int maxN = 1e3 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    map<int, int> cnt;
    map<pair<int, int>, int> kek;
    int n; cin >> n;
    ll answer = 0;
    range(i, n) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        answer += cnt[a];
        cnt[a]++;
        if (a != b) {
            answer += cnt[b];
            cnt[b]++;
            answer -= kek[{a, b}];
            kek[{a, b}]++;
        }
    }
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}