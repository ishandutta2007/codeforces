#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 150001;
ll md = 1000000007;

int get_max(int pos, vector<int> &v) {
    if (pos == -1) {
        int ans = 0;
        for(auto x: v) ans = max(x, ans);
        return ans;
    }
    vector<int> a;
    vector<int> b;
    for(auto x: v) {
        if (x & (1 << pos)) {
            a.push_back(x);
        } else {
            b.push_back(x);
        }
    }
    if (a.empty()) {
        return get_max(pos - 1, b);
    }
    if (b.empty()) {
        range(i, a.size()) a[i] ^= (1 << pos);
        return get_max(pos - 1, a);
    }
    range(i, b.size()) b[i] ^= (1 << pos);
    return min(get_max(pos - 1, a), get_max(pos - 1, b));
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    range(i, n) cin >> v[i];
    cout << get_max(29, v);
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