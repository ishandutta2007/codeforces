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
const int LG = 20;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    for(int len = 1; len <= 100; ++len) {
        set<string> has;
        for(int l = 0; l + len <= n; ++l) {
            string w;
            for(int i = l; i < l + len; ++i) w += s[i];
            has.insert(w);
        }
        string t;
        auto rec = [&] (auto self, int i) -> bool {
            if (i == len) {
                return !has.count(t);
            }
            for(char x = 'a'; x <= 'z'; ++x) {
                t += x;
                if (self(self, i + 1)) return true;
                t.pop_back();
            }
            return false;
        };
        if (rec(rec, 0)) {
            cout << t << "\n";
            return;
        }
    }
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