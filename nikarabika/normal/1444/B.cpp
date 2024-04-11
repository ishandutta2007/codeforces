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

const LL Mod = 998244353;

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

LL fact(LL x) {
    LL ans = 1;
    for (int i = 1; i <= x; i++)
        ans = ans * i % Mod;
    return ans;
}

LL comb(LL n, LL r) {
    LL facn = fact(n),
       facr = fact(r),
       facnr = fact(n - r);
    return (facn * Pow(facr, Mod - 2) % Mod) * Pow(facnr, Mod - 2) % Mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    LL a[n + n];
    for (int i = 0; i < n + n; i++)
        cin >> a[i];
    sort(a, a + n + n);
    LL sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[n + n - i - 1] - a[i];
    sum %= Mod;
    cout << 2 * sum * comb(2 * n - 1, n) % Mod << '\n';
	return 0;
}