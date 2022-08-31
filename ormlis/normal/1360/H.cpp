#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 5000 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int m;
    auto get_ll = [&](string &s) {
        ll res = 0;
        for (auto &x: s) {
            res *= (ll) 2;
            if (x == '1') res++;
        }
        return res;
    };

    auto get_string = [&](ll x) {
        string s = "";
        for (ll i = m - 1; i >= 0; --i) {
            if (x & (1LL << i)) s += "1";
            else s += "0";
        }
        return s;
    };

    int n;
    cin >> n >> m;

    vector<ll> ban;
    range(i, n) {
        string s; cin >> s;
        ll x = get_ll(s);
        ban.push_back(x);
    }
    sort(all(ban));
    ll L = -1, R = 1LL << (ll)m;
    ll e = (R - n - 1) / 2 + 1;

    auto get = [&] (ll x) {
        int i = upper_bound(all(ban), x) - ban.begin();
        return x + 1 - i;
    };

    while(R - L > 1) {
        ll mid = (R + L) / 2;
        if (get(mid) >= e) {
            R = mid;
        } else {
            L = mid;
        }
    }
    cout << get_string(R) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}