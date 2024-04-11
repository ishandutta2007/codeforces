#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 2001;

vector<int> g[maxN];
int C[maxN];
int cur = 100;

vector<int> dfs(int v) {
    vector<int> a;
    for (auto u: g[v]) {
        for (auto x: dfs(u)) {
            a.push_back(x);
        }
    }
    if (C[v] > a.size()) {
        cout << "NO";
        exit(0);
    }
    a.insert(a.begin() + C[v], v);
    return a;
}

void solve() {
    int n;
    cin >> n;
    range(i, n) {
        int r, c;
        cin >> r >> c;
        g[r].push_back(i + 1);
        C[i + 1] = c;
    }
    C[0] = 0;
    vector<int> ans = dfs(0);
    vector<int> answer(n + 1);
    for(int i = 0; i <= n; ++i) {
        answer[ans[i]] = i;
    }
    cout << "YES\n";
    for(int i = 1; i <= n; ++i) {
        cout << answer[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    //cin >> tests;
    tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}