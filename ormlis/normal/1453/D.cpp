#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < (n); ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 1e9;
const int maxN = 3e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    ull k;
    cin >> k;
    if (k % 2 == 1) {
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    while (k) {
        ull cur = 2;
        ans.push_back(1);
        for (ull i = 2; i <= 63; ++i) {
            cur += 1ull << i;
            if (cur > k) {
                cur -= 1ull << i;
                break;
            }
            ans.push_back(0);
        }
        k -= cur;
    }
    cout << ans.size() << '\n';
    for(auto &x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}