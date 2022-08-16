#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

void solve() {
    // at most a + b + 1 people in party
    // is k possible, then I can be in some range, see if all ranges are satisfiable:
    
    int n; cin >> n;
    vector<ar<int, 2>> a(n); for (auto& [x, y] : a) cin >> x >> y;

    auto can = [&](int k) {
        int cur = 0;
        for (auto& [x, y] : a) {
            if (cur <= y && k - 1 - cur <= x) {
                cur++;
            }
        }
        return cur >= k;
    };

    int lo = 0, hi = n + 1, mid = (lo + hi) / 2;
    while (lo < mid && mid < hi) {
        if (can(mid)) lo = mid;
        else hi = mid;
        mid = (lo + hi) / 2;
    }
    cout << lo << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}