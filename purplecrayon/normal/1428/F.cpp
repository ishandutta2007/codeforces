#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

int n;
string s;

int cost(int l, int r) {
    int run = 0;
    int ans = 0;
    for (int i = l; i <= r; i++) {
        if (s[i] == '1') run++;
        else run = 0;
        ans = max(ans, run);
    }
    return ans;
}
int should(int l, int r) {
    int m = (l+r)/2;
    int ans = 0;
    for (int i = l; i <= m; i++) for (int j = m+1; j <= r; j++)
        ans += cost(i, j);
    return ans;
}
ll get(vector<int>& a, vector<int>& b, bool eq) {
    int p = 0;
    ll ans = 0;
    for (auto c : b) {
        while (p < sz(a) && (a[p] < c || (eq && a[p] == c))) p++;
        ans += (long long) p * c;
    }
    return ans;
}
ll rec(int l, int r) {
    if (l > r) return 0;
    if (l == r) return s[l]-'0';
    int m = (l+r)/2;

    int m1 = m, m2 = m+1;
    while (m1 >= l && s[m1] == '1') m1--;
    while (m2 <= r && s[m2] == '1') m2++;
    m1++, m2--;

    ll ans = 0;
    int mid_len = m2-m1+1;
    if (m1 <= m && m2 > m) {
        for (int i = m1; i <= m2; i++) {
            ll cur = ll(min(m, i)-m1+1)*ll(m2-max(m+1, i)+1);
            ans += cur;
        }
    }
    vector<int> a, b;
    vector<int> a_no_mid, b_no_mid;

    int run_a = 0, ans_a = max(0, mid_len);
    int ans_a_no_mid = 0;
    for (int i = m1-1; i >= l; i--) {
        if (s[i] == '1') run_a++;
        else run_a = 0;
        ans_a = max(ans_a, run_a);
        ans_a_no_mid = max(ans_a_no_mid, run_a);

        a.push_back(ans_a);
        a_no_mid.push_back(ans_a_no_mid);
    }

    int run_b = 0, ans_b = max(0, mid_len);
    int ans_b_no_mid = 0;
    for (int i = m2+1; i <= r; i++) {
        if (s[i] == '1') run_b++;
        else run_b = 0;
        ans_b = max(ans_b, run_b);
        ans_b_no_mid = max(ans_b_no_mid, run_b);

        b.push_back(ans_b);
        b_no_mid.push_back(ans_b_no_mid);
    }

    ans += get(a, b, 0) + get(b, a, 1);
    // for (auto x : a) for (auto y : b) ans += max(x, y);

    int left_len = m-m1+1, right_len = m2-(m+1)+1;

    auto pre_sum = [&](int r) {
        return (long long) r * (r + 1) / 2;
    };
    auto sum_range = [&](int l, int r) -> ll {
        ll ret = 0;
        if (r < l) return 0;
        return pre_sum(r)-pre_sum(l-1);
    };
    auto get_sum = [&](int x, int l, int r) -> ll {
        if (r < l) return 0;
        if (x >= r) return (long long) x * (r-l+1);
        if (x < l) return sum_range(l, r);

        int cnt_one = max(0, x-l+1);
        int l_two = x+1, r_two = r;

        return (long long) x * cnt_one + sum_range(l_two, r_two);
    };

    for (auto x : a_no_mid) {
        ans += get_sum(x, left_len+1, left_len+right_len);
        /*
        for (int i = left_len+1; i <= left_len+right_len; i++) {
            ans += max(x, i);
        }
        */
    }
    for (auto y : b_no_mid) {
        ans += get_sum(y, right_len+1, right_len+left_len);
        /*
        for (int i = right_len+1; i <= right_len+left_len; i++) {
            ans += max(y, i);
        }
        */
    }
    // assert(ans == should(l, r));
    return ans + rec(l, m) + rec(m+1, r);
}
void solve() {
    cin >> n >> s;
    ll ans = rec(0, n-1);
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}