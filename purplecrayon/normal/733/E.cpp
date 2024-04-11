#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

auto get(string s) {
    int n = sz(s);
    vector<int> loc_up, loc_down;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') loc_down.push_back(i);
        else loc_up.push_back(i);
    }

    vector<ll> pre_down(sz(loc_down));
    for (int i = 0; i < sz(loc_down); i++) {
        pre_down[i] = loc_down[i];
        if (i) pre_down[i] += pre_down[i-1];
    }
    auto sum_down = [&](int L, int R) {
        return pre_down[R] - (L ? pre_down[L-1] : 0);
    };

    vector<ll> pre_up(sz(loc_up));
    for (int i = 0; i < sz(loc_up); i++) {
        pre_up[i] = loc_up[i];
        if (i) pre_up[i] += pre_up[i-1];
    }
    auto sum_up = [&](int L, int R) {
        return pre_up[R] - (L ? pre_up[L-1] : 0);
    };

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; i++) if (s[i] == 'D') {
        int cnt_one = upper_bound(loc_up.begin(), loc_up.end(), i) - loc_up.begin();
        int cnt_two = sz(loc_down) - (upper_bound(loc_down.begin(), loc_down.end(), i) - loc_down.begin());
        int k = min(cnt_one, cnt_two);
        
        int use_down = upper_bound(loc_down.begin(), loc_down.end(), i) - loc_down.begin();
        int use_up = upper_bound(loc_up.begin(), loc_up.end(), i) - loc_up.begin() - 1;

        ll cur = 0;
        if (k) {
            cur += sum_down(use_down, use_down + k - 1);
            cur -= sum_up(use_up - k + 1, use_up);
        }

        cur *= 2;
        if (cnt_one <= cnt_two) cur += i + 1;
        else cur += i - loc_up[use_up - k] + n - loc_up[use_up - k];
        ans[i] = cur;
    }
    return ans;
}
void solve() {
    int n; cin >> n;
    string s; cin >> s;

    auto one = get(s);
    for (auto& c : s) c ^= 'U' ^ 'D';
    reverse(s.begin(), s.end());
    auto two = get(s);
    reverse(two.begin(), two.end());
    for (int i = 0; i < n; i++) {
        cout << max(one[i], two[i]) << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}