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

const LL Mod = 1000 * 1000 * 1000 + 7;

LL doaz(LL x) {
    x %= Mod;
    return x * (x - 1) / 2 % Mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    for (auto &c: s)
        c -= '0';
    LL pow = 1;
    LL sum = 0;
    LL ans = 0;
    reverse(all(s));
    for (int i = 0; i < sz(s); i++) {
        ans = (ans + sum * s[i]) % Mod;
        ans = (ans + doaz(sz(s) - i) * s[i] % Mod * pow) % Mod;

        sum += (i + 1) * pow % Mod;
        sum %= Mod;
        pow = (pow * 10) % Mod;
    }
    cout << ans << '\n';
	return 0;
}