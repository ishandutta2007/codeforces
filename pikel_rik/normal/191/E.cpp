#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

template <typename T>
class FenwickTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> bit;
    F f;

    FenwickTree(): n(), bit(), f() {}
    FenwickTree(int n, F f = plus<T>()): n(n), bit(n + 1, 0), f(f) {}

    void add(int i, int val) {
        while (i <= n) {
            bit[i] = f(bit[i], val);
            i += i & -i;
        }
    }
    T query(int i) {
        T ans = T();
        while (i > 0) {
            ans = f(ans, bit[i]);
            i -= i & -i;
        }
        return ans;
    }
};

const int N = 1e5 + 5;
int n, a[N];
ll k;
vector<ll> pref;

bool f(ll x) {
    FenwickTree<int> ft(pref.size());

    ll sum = 0, larger = 0;
    for (int i = 0; i <= n; i++) {
        sum += a[i];
        int idx = lower_bound(pref.begin(), pref.end(), sum) - pref.begin();
        int idx1 = lower_bound(pref.begin(), pref.end(), sum - x) - pref.begin();
        if (idx1 > 0)
            larger += ft.query(idx1);
        ft.add(idx + 1, 1);
    }
//    cout << x << ' ' << larger << '\n';
    return larger < k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += a[i];
        pref.push_back(sum);
    }

    sort(pref.begin(), pref.end());
    pref.erase(unique(pref.begin(), pref.end()), pref.end());

    ll lo = 0, hi = (ll)2e14;

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (f(mid - (ll)1e14))
            hi = mid;
        else lo = mid + 1;
    }

    cout << lo - (ll)1e14 << '\n';
    return 0;
}