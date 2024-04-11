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
const int maxN = 3e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }
int n;
vector<pair<int, int>> edges;
vector<int> query(int r) {
    cout << '?' << ' ' << r + 1 << endl;
    vector<int> d(n);
    range(i, n) {
        cin >> d[i];
        if (d[i] == 1) edges.emplace_back(min(r, i), max(r, i));
    }
    return d;
}

void solve() {
    cin >> n;
    auto d = query(0);
    vector<int> a;
    vector<int> b;
    for(int i = 1; i < n; ++i) {
        if (d[i] & 1) a.push_back(i);
        else b.push_back(i);
    }
    if (a.size() > b.size()) swap(a, b);
    for(auto &i : a) {
        query(i);
    }
    sort(all(edges));
    edges.resize(unique(all(edges)) - edges.begin());
    cout << "!" << endl;
    for(auto &[a, b] : edges) cout << a + 1 << ' ' << b + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}