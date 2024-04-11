#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

ll power(ll x, int k) {
    ll res = 1;
    for (int i = 0; i < k; i++) res *= x;
    return res;
}

pair<bool, ll> root(ll n, int k) {
    ll left = 0;
    ll right = (ll) pow(n, 1.0 / k) + 10;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        if (power(mid, k) >= n) {
            right = mid;
        } else {
            left = mid;
        }
    }
    if (power(right, k) == n) {
        return {true, right};
    } else {
        return {false, right};
    }
}

pair<bool, vector<ll>> factorize(ll n) {
    auto res1 = root(n, 4);
    if (res1.first) {
        return {true, {res1.second, res1.second, res1.second, res1.second}};
    }
    auto res2 = root(n, 3);
    if (res2.first) {
        return {true, {res2.second, res2.second, res2.second}};
    }
    auto res3 = root(n, 2);
    if (res3.first) {
        return {true, {res3.second, res3.second}};
    }
    return {false, {}};
}

void run() {
    int n;
    cin >> n;
    map<ll, int> cnt;
    vector<ll> a(n);
    vector<ll> other;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        auto tmp = factorize(a[i]);
        if (tmp.first) {
            for (ll d : tmp.second) {
                cnt[d]++;
            }
        } else {
            other.push_back(a[i]);
        }
    }
    vector<ll> cool;
    for (auto &it : cnt) {
        cool.push_back(it.first);
    }
    for (int i = 0; i < (int) other.size(); i++) {
        for (int j = i + 1; j < (int) other.size(); j++) {
            if (other[i] == other[j]) continue;
            ll kek = __gcd(other[i], other[j]);
            if (kek > 1) {
                cool.push_back(kek);
            }
        }
    }
    map<ll, int> cc;
    for (ll x : other) {
        bool ok = false;
        for (ll d : cool) {
            if (x % d == 0) {
                cnt[d]++;
                cnt[x / d]++;
                ok = true;
                break;
            }
        }
        if (!ok) cc[x]++;
    }
    ll ans = 1;
    for (auto &it : cc) {
        ans *= (it.second + 1) * (it.second + 1);
        ans %= 998244353;
    }
    for (auto &it : cnt) {
        ans *= (it.second + 1);
        ans %= 998244353;
    }
    cout << ans << "\n";
}