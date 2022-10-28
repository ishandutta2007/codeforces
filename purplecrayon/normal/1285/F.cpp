#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;

int pf[N];

void pre() {
    memset(pf, -1, sizeof(pf));
    for (int i = 2; i < N; i++) if (pf[i] == -1) {
        for (int j = i; j < N; j += i) pf[j] = i;
    }
}

struct {
    int cnt[N];
    int sz = 0;

    void clear() {
        memset(cnt, 0, sizeof(cnt));
        sz = 0;
    }
    vector<int> get_primes(int x) {
        int start = x;
        vector<int> ans;
        while (x > 1) {
            int p = pf[x];
            while (x % p == 0) {
                x /= p;
            }
            ans.push_back(p);
        }
        return ans;
    }
    void upd(int x, int d) {
        sz += d;
        auto primes = get_primes(x);
        for (int m = 1; m < (1 << sz(primes)); m++) {
            int cur = 1;
            for (int j = 0; j < sz(primes); j++) if ((m >> j) & 1) cur *= primes[j];
            cnt[cur] += d;
        }
    }
    void add(int x) {
        upd(x, +1);
    }
    void er(int x) {
        upd(x, -1);
    }
    int qry(int x) {
        auto primes = get_primes(x);
        int ans = sz;
        for (int m = 1; m < (1 << sz(primes)); m++) {
            int cur = 1;
            for (int j = 0; j < sz(primes); j++) if ((m >> j) & 1) cur *= primes[j];
            ans += (__builtin_popcount(m) % 2 ? -1 : 1) * cnt[cur];
        }
        return ans;
    }
    int qry_if_rem(int x, int cand) {
        return qry(x) - (std::gcd(x, cand) == 1);
    }
} store;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;

    int m = *max_element(a.begin(), a.end());
    vector<bool> has(m + 1);
    for (int x : a) has[x] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j += i) if (has[j]) {
            has[i] = 1;
            break;
        }
    }
    vector<int> use; use.reserve(m);
    store.clear();
    for (int i = 1; i <= m; i++) if (has[i]) {
        store.add(i);
        use.push_back(i);
    }
    ll ans = use.back();

    int p = 0;
    for (int i = sz(use)-1; i >= 0; i--) {
        while (p < i && store.qry_if_rem(use[i], use[p])) store.er(use[p++]);
        if (p < i && store.qry(use[i])) {
            assert(std::gcd(use[i], use[p]) == 1);
            ans = max(ans, (long long) use[i] * use[p]);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    pre();
    // cin >> T;
    while (T--) solve();
}