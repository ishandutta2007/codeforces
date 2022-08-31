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

vector<int> Zfunc(const string &s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r= 0 ;
    range(i, n) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while(i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
    return z;
}

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    auto z = Zfunc(s);
    int j = n;
    string ans;
    range(i, k) {
        if (j == n) {
            ans += s[0];
            j = 1;
            continue;
        }
        int d = z[j];
        if (j + d == n || s[j + d] > s[d]) {
            ans += s[0];
            j = 1;
            continue;
        }
        ans += s[j];
        j++;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}