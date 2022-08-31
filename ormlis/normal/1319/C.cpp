//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < n; ++i)
#define all(arr) arr.begin(), arr.end()
#define rall(arr) arr.rbegin(), arr.rend()


using namespace std;

typedef long long ll;
const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e5;
const int md = 998244353;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    range(i, n) {
        for(int j = 25; j >= 0; --j) {
            int ans = -1;
            range(e, s.size()) {
                if (s[e] - 'a' == j && (s[max(e-1, 0)] - 'a' == j - 1 || s[min(e+1, (int)s.size()-1)] - 'a' == j - 1)) {
                    ans = e;
                    break;
                }
            }
            if (ans != -1) {
                s = s.substr(0, ans) + s.substr(ans+1, s.size());
                break;
            }
        }
    }
    cout << n - s.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //auto sad = mt19937(2231337);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}