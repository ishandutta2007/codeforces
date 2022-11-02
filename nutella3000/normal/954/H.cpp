#include <bits/stdc++.h>
using namespace std;

#define chkmin(a, b) a = min(a, b);
#define chkmax(a, b) a = max(a, b)
#define int long long
#define size(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair

const int inf = 1e9 + 7, mod = 1e9 + 7;
const int max_n = 5002;


int sum(int a, int b) {
    int res = a + b;
    if (res >= mod) res -= mod;
    return res;
}
int mul(int a, int b) { return a * b % mod; }

int binpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res;
}

int rev(int a) { return binpow(a, mod - 2); }

int n;
int a[max_n], pref[max_n];
int f[2 * max_n], dp[2 * max_n];

void scan() {
    cin >> n;
    pref[0] = 1;
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        pref[i] = mul(pref[i - 1], a[i]);
    }
}

void run() {
    scan();
    for (int i = n; i > 0; --i) {
        f[0] = 1;
        vector<int> pr(n + 2 * n + 4);
        pr[i - 1] = 1;
        for (int j = i; j < n; ++j)
            pr[j] = mul(pr[j - 1], a[j]);

        for (int len = 2 * n; len >= 1; --len) {

            int kek = 0;
            if (len >= 2) kek = mul((a[i] * (a[i] - 1) / 2) % mod, f[len - 2]);
            dp[len] = sum(dp[len], mul(pref[i - 1], sum(pr[i + len - 1], kek)));

            f[len] = 0;
            if (len >= 2) f[len] = mul(mul(a[i], a[i]), f[len - 2]);
            f[len] = sum(f[len], mul(2, pr[i + len - 1]));
        }
    }
    for (int i = 1; i <= 2 * n - 2; ++i)
        cout << dp[i] << " ";
    cout << endl;
}


signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    run();
}