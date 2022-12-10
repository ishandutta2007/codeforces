//sobskdrbhvk
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 1e5 + 10;
const LL Mod = 1e9 + 9;
LL sign[maxn];

LL Pow(LL x, LL y) {
	LL an = x,
	   ans = 1;
	while (y) {
		if (y & 1)
			ans = (ans * an) % Mod;
		an = an * an % Mod;
		y >>= 1;
	}
	return ans;
}

LL Div(LL x, LL y) {
	return x * Pow(y, Mod - 2) % Mod;
}

int main() {
	LL n, a, b, k;
	string s;
	cin >> n >> a >> b >> k;
	cin >> s;
	for (int i = 0; i < k; i++)
		sign[i] = (s[i] == '-' ? -1 : +1);
	LL ans = 0;
	int np = n;
	LL tmp = 1;
	LL D = Pow(Div(b, a), k);
	for (int i = 0; i < k and i <= n; i++, np--) {
		//base = a ^ n
		//D = b ^ k / a ^ k
		// base * (D ^ 0 + D ^ 1 + ... + D ^ cnt) = base * D ^ (cnt + 1) / (D - 1)
		LL cnt = np / k;
		LL base = Pow(a, np);
		LL sum = (D == 1 ? base * (cnt + 1) : Div(base * (Pow(D, cnt + 1) - 1) % Mod, D - 1));
		ans += (sum * sign[i] % Mod) * tmp % Mod;
		ans %= Mod;
		tmp = tmp * b % Mod;
	}
	ans = (ans + Mod) % Mod;
	cout << ans << endl;
	return 0;
}