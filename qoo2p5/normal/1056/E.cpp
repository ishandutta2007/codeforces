#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);

bool mini(auto& x, const auto& y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

bool maxi(auto& x, const auto& y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

const ll MOD = (ll) (1e9 + 7);
const ll P[2] = {179, 239};

const int N = (int) (2e6 + 123);

string s, t;
int n, m;
ll h[N][2];
ll p[N][2];
int z;

pair<ll, ll> get(int l, int r) {
    l++, r++;
    ll res[2];
    for (int i = 0; i < 2; i++) {
        res[i] = h[r][i];
        res[i] -= h[l - 1][i] * p[r - l + 1][i] % MOD;
        if (res[i] < 0) {
            res[i] += MOD;
        }
    }
    return {res[0], res[1]};
}

bool check(int a, int b) {
    // assert(a * z + b * (n - z) == m);
    int pos0 = -1;
    int pos1 = -1;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (pos0 == -1) {
                pos0 = cur;
            cur += a;
                continue;
            }
            if (get(pos0, pos0 + a - 1) != get(cur, cur + a - 1)) {
                return false;
            }
            cur += a;
        } else if (s[i] == '1') {
            if (pos1 == -1) {
                pos1 = cur;
            cur += b;
                continue;
            }
            if (get(pos1, pos1 + b - 1) != get(cur, cur + b - 1)) {
                return false;
            }
            cur += b;
        }
    }
    auto h1 = get(pos0, pos0 + a - 1);
    auto h2 = get(pos1, pos1 + b - 1);
    if (h1 == h2) {
        return false;
    }
    return true;
}

void run() {
    cin >> s >> t;
    for (char c : s) {
        if (c == '0') {
            z++;
        }
    }
    n = (int) s.size();
    m = (int) t.size();
    if (2 * z >= n) {
        z = n - z;
        for (char& c : s) {
            if (c == '0') {
                c = '1';
            } else {
                c = '0';
            }
        }
    }
    // assert(n - z >= n / 2 - 1);

    for (int i = 0; i < 2; i++) {
        p[0][i] = 1;
        for (int j = 1; j < N; j++) {
            p[j][i] = (p[j - 1][i] * P[i]) % MOD;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= m; j++) {
            h[j][i] = (h[j - 1][i] * P[i] + t[j - 1]) % MOD;
        }
    }

    int ans = 0;
    for (ll a = 1; a <= m; a++) {
        ll r = m - a * z;
        if (r > 0 && r % (n - z) == 0) {
            ll b = r / (n - z);
            ans += check(a, b);
        }
    }
    cout << ans << "\n";
}