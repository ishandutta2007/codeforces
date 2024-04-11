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
typedef __int128 i128;

const int INFi = 2e9 + 5;
const int maxN = 1e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    string t;
    cin >> t;
    vector<int> cnt(26);
    vector<int> ord;
    for (int i = (int) t.size() - 1; i >= 0; --i) {
        if (cnt[t[i] - 'a']++) continue;
        ord.push_back(t[i] - 'a');
    }
    int r = 0;
    int ops = ord.size();
    vector<int> cur(26);
    vector<bool> blocked(26);
    range(i, ops) {
        if (cnt[ord[i]] % (ops - i) != 0) {
            cout << "-1\n";
            return;
        }
        int need = cnt[ord[i]] / (ops - i);
        if (cur[ord[i]] > need) {
            cout << "-1\n";
            return;
        }
        while (cur[ord[i]] < need) {
            cur[t[r] - 'a']++;
            if (blocked[t[r] - 'a']) {
                cout << "-1\n";
                return;
            }
            r++;
        }
    }
    string s = t.substr(0, r);
    reverse(all(ord));
    string w;
    for(auto &c : ord) {
        w += s;
        string s2;
        for(auto &c2 : s) if (c2 != char(c + 'a')) s2 += c2;
        s = s2;
    }
    if (w != t) {
        cout << "-1\n";
        return;
    }
    cout << t.substr(0, r) << ' ';
    for (auto &c : ord) cout << char(c + 'a');
    cout << '\n';
}

signed main() {
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