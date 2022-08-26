#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

//using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 20;
const int md2 = 998244353;
const int md = 1e9 + 7;


void solve() {
    string s; cin >> s;
    int ans = 0;
    for(int i = 1; i < (int)s.size(); ++i) {
        if (s[i] == s[i - 1] || (i > 1 && s[i] == s[i - 2])) {
            ans++;
            s[i] = 0;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}