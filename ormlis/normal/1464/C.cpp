#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
using namespace std;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

void solve() {
    ll n, T; cin >> n >> T;
    string s; cin >> s;
    T += 1 << (s[n - 2] - 'a');
    T -= 1 << (s[n - 1] - 'a');
    vector<int> cnt(26);
    for(int i = 0; i + 2 < n; ++i) cnt[s[i] - 'a']++;
    T = abs(T);
    ll T2 = 0;
    range(i, 26) {
        T2 += (1ll << i) * cnt[i];
    }
    T2 -= T;
    if (T2 % 2 != 0) {
        cout << "No\n";
        return;
    }
    T2 /= 2;
    int cur = 0;
    range(i, 62) {
        ll bt = 1ll << i;
        if (i < 26) cur += cnt[i];
        if (T2 & bt) {
            if (!cur) {
                cout << "No\n";
                return;
            }
            cur--;
        }
        cur /= 2;
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}