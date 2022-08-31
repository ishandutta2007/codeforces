#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

ll modexp(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return ans;
}

ll modinv(ll x) {
    return modexp(x, mod - 2);
}

int n, p, a[N], cnt[N];

bool f(int x) {
    for (int i = 0; i < n; i++) {
        int c = upper_bound(a, a + n, x) - a;
        if (c - i == 0)
            return false;
        x++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> p;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans;
    sort(a, a + n);

    int lo = 1, hi = 1e9;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (f(mid))
            hi = mid;
        else lo = mid + 1;
    }

    deque<int> vals;
    int x = lo;

    for (int i = 0; i < n; i++) {
        int c = upper_bound(a, a + n, x) - a;
        vals.push_back((c - i) % p);
        cnt[(c - i) % p]++;
        x++;
    }

    if (!cnt[0])
        ans.push_back(lo);

    int cur = 1;
    for (int j = lo + 1; j <= a[n - 1] - 1; j++) {
        cnt[vals.front() % p]--;
        vals.pop_front();

        int c = upper_bound(a, a + n, j + n - 1) - a;
        int val = ((c - n + 1 - cur) % p + p) % p;
        vals.push_back(val);

        cnt[val]++;

        if (!cnt[(p - cur) % p])
            ans.push_back(j);
        cur = (cur + 1) % p;
    }

    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " "; cout << "\n";
    return 0;
}