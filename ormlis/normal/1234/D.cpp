#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 1e9;
const int maxN = 400000 + 2000;
const int md = 998244353;
const int md2 = 1e9 + 7;

// double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    vector<set<int>> v(26);
    string s; cin >> s;
    range(i, (int)s.size()) v[s[i] - 'a'].insert(i);
    int q; cin >> q;
    range(i, q) {
        int t; cin >> t;
        if (t == 1) {
            int pos; char c; cin >> pos >> c;
            pos--;
            v[s[pos] - 'a'].erase(pos);
            s[pos] = c;
            v[s[pos] - 'a'].insert(pos);
        } else {
            int l, r; cin >> l >> r;
            l--;
            int ans = 0;
            range(j, 26) {
                auto k = v[j].lower_bound(l);
                if (k != v[j].end() && *k < r) ans++;
            }
            cout << ans << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}