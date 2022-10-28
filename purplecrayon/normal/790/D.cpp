#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

// I only care about states where the answer >= current maximum - 1
struct S { 
    int ans;
    set<ll> one, two;

    S() {}
    S(int _start, ll ps_one, ll ps_two): ans(_start) {
        one.insert(ps_one);
        two.insert(ps_two);
    }
    void add(ll ps_one, ll ps_two) {
        if (one.count(ps_one)) ans++, one.clear();
        if (two.count(ps_two)) ans++, two.clear();
        one.insert(ps_one), two.insert(ps_two);
    }
};

void solve() {
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> dp(n + 1); // everything ends <= i
    deque<int> use{n};

    vector<S> bag(n + 1);
    bag[n] = S(0, 0, 0);

    ll ps_a = 0, ps_b = 0;
    map<ll, int> both;
    both[0] = 0;

    for (int i = 0; i < n; i++) {
        if (i) dp[i] = dp[i-1];

        ps_a += a[i], ps_b += b[i];
        if (both.count(ps_a + ps_b)) {
            dp[i] = max(dp[i], 1 + both[ps_a + ps_b]);
        }

        for (auto& c : use) {
            auto& cand = bag[c];
            cand.add(ps_a, ps_b);
            dp[i] = max(dp[i], cand.ans);
        }

        bag[i] = S(dp[i], ps_a, ps_b);
        while (sz(use) && bag[use.front()].ans < dp[i] - 1) {
            use.pop_front();
        }
        if (!sz(use) || dp[use.back()] != dp[i]) {
            use.push_back(i);
        }
        deque<int> new_use;
        for (int c : use) {
            if (!sz(new_use) || bag[new_use.back()].ans < bag[c].ans || (sz(bag[c].one) > sz(bag[new_use.back()].one) || sz(bag[c].two) > sz(bag[new_use.back()].two))) new_use.push_back(c);
        }
        swap(new_use, use);

        both[ps_a + ps_b] = max(both[ps_a + ps_b], dp[i]);
    }
    cout << dp[n-1] << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}