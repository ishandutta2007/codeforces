#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

ll c2(ll x) {
    return x * (x - 1) / 2;
}
ll c3(ll x) {
    return x * (x - 1) * (x - 2) / 6;
}
ll get(const vector<int>& one, const vector<int>& two, int k) {
    int j = sz(two) - 1;
    assert(std::is_sorted(one.begin(), one.end()));
    assert(std::is_sorted(two.begin(), two.end()));
    ll ans = 0;
    for (int i = 0; i < sz(one); i++) {
        while (j >= 0 && two[j] > one[i] && two[j] + one[i] > k) j--;
        while (j < sz(two) - 1 && two[j+1] <= one[i]) j++;
        ans += sz(two) - j - 1;
    }
    return ans;
}
void solve() {
    // iterate over the lcm
    // k = lcm / 2, or k = lcm
    // if k = lcm / 2:
    //      i + j >= k
    // else: 
    //      i + j <= 0
    //
    // only care about k = lcm / 2, all other pairs are trivial

    int l, r; cin >> l >> r;
    vector<vector<int>> factors(2 * r + 1);
    for (int i = l; i <= r; i++) {
        for (int j = 2 * i; j < sz(factors); j += i) {
            factors[j].push_back(i);
        }
    }
    ll ans = 0;
    for (int p = l; p <= 2 * r; p++) {
        if (p <= r) ans += c2(sz(factors[p]));
        if (p % 2 == 0 && p / 2 >= l) {
            int k = p / 2;
            ll cnt = 0;
            vector<int> one, two;
            for (int i : factors[p]) if (i < k) {
                if (k % i) one.push_back(i);
                else two.push_back(i);
            }
            cnt = get(one, one, k) + get(one, two, k) + get(two, one, k);
            /*
            for (int i : factors[p]) for (int j : factors[p]) {
                if (i < j && j < k && (k % i || k % j) && i + j > k)
                    cnt++;
            }
            */
            ans += cnt;
        }
    }
    cout << c3(r - l + 1) - ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}