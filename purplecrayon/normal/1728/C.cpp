#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;


void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<int> b(n); for (auto& x : b) cin >> x;

    auto op = [&](int x) {
        return sz(to_string(x));
    };

    priority_queue<int> one, two;
    for (int x : a) one.push(x);
    for (int x : b) two.push(x);

    int ans = 0;
    while (sz(one) || sz(two)) {
        int x = one.top(), y = two.top();
        if (x > y) swap(x, y), swap(one, two);
        if (x == y) {
            one.pop(), two.pop();
            continue;
        }

        two.pop(); two.push(op(y));
        ans++;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}