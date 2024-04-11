//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 5000 + 100;
const LL Mod = 998244353;
LL fact[maxn],
   inv[maxn];
LL dp[maxn];
int last[maxn],
    bighalf[maxn],
    a[maxn],
    n;

LL Pow(LL x, LL y) {
    LL ans = 1,
       an = x;
    while (y) {
        if (y & 1LL)
            ans = ans * an % Mod;
        an = an * an % Mod;
        y >>= 1;
    }
    return ans;
}

LL P(int x, int y) {
    static bool comped = false;
    if (!comped) {
        comped = true;
        fact[0] = 1;
        inv[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = fact[i - 1] * i % Mod;
            inv[i] = Pow(fact[i], Mod - 2);
        }
    }
    return fact[x + y] * inv[x] % Mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n++] = 0;
    sort(a, a + n);
    for (int i = 1; i < n; i++) {
        last[i] = upper_bound(a, a + i, a[i] / 2) - a;
        bighalf[i] = i - last[i];
    }
    if (n >= 2 and a[n - 2] * 2 > a[n - 1])
        return cout << 0 << '\n', 0;
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i and a[j] >= 2 * a[i]; j--) {
            LL cur = 0;
            LL all = j - i - 1;
            LL ri = all - bighalf[j];
            LL le = bighalf[i];
            cur = dp[j] * P(n - j + bighalf[j] - 1, ri) % Mod;
            cur = cur * P(n - i - 2, le);
            dp[i] = (dp[i] + cur) % Mod;
            //cerr << "--> " << i << ' ' << j << ' ' << cur << ' ' << le << ' ' << ri << ' ' << P(n - j + bighalf[j] - 1, ri) << '\n';
        }
    }
    cout << dp[0] << '\n';
	return 0;
}