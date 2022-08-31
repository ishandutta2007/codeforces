#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

ll solve(int n, vector<pair<ll, int>> &b, vi &cnt) {
    vi bgL(n, -1), bgR(n, n);
    vi lwR(n, n);
    {
        vector<int> stk;
        rep(i, n) {
            while (!stk.empty() && b[stk.back()] < b[i]) stk.pop_back();
            if (!stk.empty()) {
                bgL[i] = stk.back();
            }
            stk.push_back(i);
        }
    }
    {
        vector<int> stk;
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && b[stk.back()] < b[i]) stk.pop_back();
            if (!stk.empty()) {
                bgR[i] = stk.back();
            }
            stk.push_back(i);
        }
    }
    {
        vector<int> stk;
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && b[stk.back()] > b[i]) stk.pop_back();
            if (!stk.empty()) {
                lwR[i] = stk.back();
            }
            stk.push_back(i);
        }
    }
    vector<int> stk;
    vector<vector<int>> pref(62);
    vector<vector<int>> preflen(62);
    vector<vector<int>> prefsum(62);
    vector<vector<ll>> prefssR(62);

    auto find_mid = [&](int x, int to) {
        int L = -1;
        int R = pref[x].size();
        while (R - L > 1) {
            int mid = (R + L) / 2;
            if (lwR[pref[x][mid]] >= to) {
                L = mid;
            } else {
                R = mid;
            }
        }
        return R;
    };

    ll answer = 0;

    rep(i, n) {
        while (!stk.empty() && b[stk.back()] > b[i]) {
            pref[cnt[stk.back()]].pop_back();
            preflen[cnt[stk.back()]].pop_back();
            prefsum[cnt[stk.back()]].pop_back();
            prefssR[cnt[stk.back()]].pop_back();
            stk.pop_back();
        }
        {
            int l = i + 1;
            if (!stk.empty()) l = i - stk.back();
            stk.push_back(i);
            pref[cnt[i]].emplace_back(i);
            preflen[cnt[i]].emplace_back(l);
            if (!prefsum[cnt[i]].empty()) l += prefsum[cnt[i]].back();
            prefsum[cnt[i]].push_back(l);
            ll cur = preflen[cnt[i]].back() * 1ll * lwR[i];
            if (!prefssR[cnt[i]].empty()) cur += prefssR[cnt[i]].back();
            prefssR[cnt[i]].push_back(cur);
        }
        int L = bgL[i];
        int R = bgR[i];
        int mid = find_mid(cnt[i], R);
        int x = cnt[i];
        int j = lower_bound(all(pref[x]), L + 1) - pref[x].begin();
        // [j, ..]
        ll result = 0;
        result += 1ll * min(pref[x][j] - L, preflen[x][j]) * (min(R, lwR[pref[x][j]]) - i);
        j++;
        if (j < (int) pref[x].size()) {
            mid = max(mid, j);
            result += prefssR[x].back();
            if (mid != 0) result -= prefssR[x][mid - 1];
            result -= 1ll * prefsum[x].back() * i;
            if (mid != 0) result += 1ll * prefsum[x][mid - 1] * i;
            if (j < mid) {
                // [j, mid)
                ll value = prefsum[x][mid - 1];
                if (j != 0) value -= prefsum[x][j - 1];
                result += value * (R - i);
            }
        }
        answer += result;
    }
    return answer;
}

void solve() {
    int n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];
    vector<pair<ll, int>> b(n);
    rep(i, n) b[i] = {a[i], i};
    vi cnt(n);
    rep(i, n) cnt[i] = __builtin_popcountll(a[i]);
    ll answer = solve(n, b, cnt);
    reverse(all(cnt));
    reverse(all(b));
    answer += solve(n, b, cnt);
    cout << answer - n << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(_, t) {
        solve();
    }
    return 0;
}