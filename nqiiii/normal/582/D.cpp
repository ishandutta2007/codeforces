#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3400, mod = 1e9 + 7;
int p, a;
int b[maxn + 10], bcnt, ans;
int f[maxn + 10][maxn + 10][2][2];
vector<ll> s;

void readint() {
	static char a[2000];
	scanf("%s", a); int l = strlen(a);
	reverse(a, a + l);
	for (int i = 0; i < l; i += 9) {
		ll cnt = 0, w = 1;
		for (int j = 0; j < 9 && i + j < l; ++j) {
			cnt = cnt + w * (a[i + j] - '0');
			w *= 10;
		}
		s.push_back(cnt);
	}
}

ll calc() {
	ll l = 0;
	for (int i = (int)s.size() - 1; i >= 0; --i) {
		s[i] += l * 1000000000;
		l = s[i] % p; s[i] /= p;
	}
	while (!s.empty() && !s.back()) s.pop_back();
	return l;
}


int calc1(ll l, ll r) {
	++l; ++r;
	return (l + r) * (r - l + 1) / 2 % mod;
}

int calc2(ll l, ll r) {
	int ans = (2 * p - 1) * (r - l + 1) % mod;
	ans -= (l + r) * (r - l + 1) / 2 % mod;
	return ans < 0 ? ans + mod : ans;
}

int calc(int l, int r) {
	l = max(l, 0); r = min(r, 2 * p - 1);
	if (l > r) return 0;
	if (r < p) return calc1(l, r);
	if (l >= p) return calc2(l, r);
	return (calc1(l, p - 1) + calc2(p, r)) % mod;
}

void update(int &x, int y) {
	x += y; if (x >= mod) x -= mod;
}


int main() {
	scanf("%d%d", &p, &a);
	readint();
	while (!s.empty()) 
		b[++bcnt] = calc();
	++bcnt;
	f[bcnt][0][1][0] = 1;
	for (int i = bcnt; i > 1; --i)
		for (int j = 0; j <= bcnt; ++j)
			for (int k = 0; k < 2; ++k)
				for (int l = 0; l < 2; ++l) {
					int lim = k ? b[i - 1] : p - 1;
					for (int o = 0; o < 2; ++o) {
						if (l) 
							update(f[i - 1][j + l][0][o], 1ll * f[i][j][k][l] * calc(p - o, p + lim - 1 - o) % mod);
						else 
							update(f[i - 1][j + l][0][o], 1ll * f[i][j][k][l] * calc(0, lim - 1 - o) % mod);

						if (l)
							update(f[i - 1][j + l][k][o], 1ll * f[i][j][k][l] * calc(p + lim - o, p + lim - o) % mod);
						else
							update(f[i - 1][j + l][k][o], 1ll * f[i][j][k][l] * calc(lim - o, lim - o) % mod);
					}
				}
	for (int i = a; i <= bcnt; ++i) {
		(ans += f[1][i][0][0]) %= mod;
		(ans += f[1][i][1][0]) %= mod;
	}
	printf("%d", ans);
}