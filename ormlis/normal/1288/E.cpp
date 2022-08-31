

#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 100001;
ll md = 1000000007;
int n, m;



void solve() {
    cin >> n >> m;
    indexed_set s;
    vector<int> num(n + 1, 0);
    vector<int> ma(n + 1, 0);
    vector<int> mi(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        num[i] = ma[i] = mi[i] = i;
        s.insert(i);
    }
    int cur = 0;
    range(i, m) {
        int a; cin >> a;
        mi[a] = 1;
        ma[a] = max(ma[a], (int)s.order_of_key(num[a]) + 1);
        s.erase(num[a]);
        cur--;
        s.insert(cur);
        num[a] = cur;
    }
    for(int i = 1; i <= n; ++i) {
        cout << mi[i] << " " << max(ma[i], (int)s.order_of_key(num[i]) + 1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}