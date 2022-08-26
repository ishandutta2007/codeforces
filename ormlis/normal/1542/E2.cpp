#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 1e5 + 1;
int md;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int solve(int n) {
    if (n <= 2) return 0;
    int ans = mul(n, solve(n - 1));
    int res = 0;
    int can = max((n - 2) * (n - 1) / 2, n + 5);
    vector<int> cnt(can + 1);
    cnt[0] = 1;
    range(i, n - 1) {
        vector<int> newcnt(can + 1);
        int s = 0;
        for(int j = 0; j <= can; ++j) {
            s = add(s, cnt[j]);
            if (j - i - 1 >= 0) {
                s = sub(s, cnt[j - i - 1]);
            }
            newcnt[j] = s;
        }
        swap(cnt, newcnt);
    }
    vector<int> cnt2(n + 1);
    for(int i = 1; i <= n; ++i) {
        int s = 0;
        for(int ch1 = i; ch1 <= can; ++ch1) {
            s = add(s, cnt[ch1 - i]);
            cnt2[i] = add(cnt2[i], mul(s, cnt[ch1]));
        }
    }
    for(int a = 1; a <= n; ++a) {
        for(int b = a + 1; b <= n; ++b) {
            // p = [a, ...]
            // q = [b, ...]
            int need = (b - 1) - (a - 1) + 1;
            res = add(res, cnt2[need]);
            //
        }
    }
    return add(res, ans);
}

void solve() {
    int n; cin >> n;
    cin >> md;
    vector<int> ans(n + 1);
    int can = max((n - 2) * (n - 1) / 2, n + 5);
    int mx = can * 2 + 10;
    int mid = mx;
    int sz = mid * 2 + 5;
    vector<int> cnt(sz);
    cnt[mid] = 1;
    for(int suf = 1; suf < n; ++suf) {
        {
            vector<int> newcnt(sz);
            int s = 0;
            for (int j = 0; j < sz; ++j) {
                s = add(s, cnt[j]);
                if (j - suf >= 0) {
                    s = sub(s, cnt[j - suf]);
                }
                newcnt[j] = s;
            }
            swap(cnt, newcnt);
        }
        {
            vector<int> newcnt(sz);
            int s = 0;
            for (int j = sz - 1; j >= 0; --j) {
                s = add(s, cnt[j]);
                if (j + suf < sz) {
                    s = sub(s, cnt[j + suf]);
                }
                newcnt[j] = s;
            }
            swap(cnt, newcnt);
        }
        vector<int> suf_sum(sz);
        suf_sum[sz - 1] = cnt[sz - 1];
        for(int i = sz - 2; i >= 0; --i) suf_sum[i] = add(suf_sum[i + 1], cnt[i]);
        for(int a = 1; a <= suf + 1; ++a) {
            for(int b = a + 1; b <= suf + 1; ++b) {
                int need = (b - 1) - (a - 1) + 1;
                ans[suf] = add(ans[suf], suf_sum[need + mid]);
            }
        }
        ans[suf] = add(ans[suf], mul(ans[suf - 1], suf + 1));
        //assert(ans[suf] == solve(suf + 1));
    }
    cout << ans[n - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}