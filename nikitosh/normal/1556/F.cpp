#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using vi = vector<int>;
using pii = pair<int, int>;

const int N = 15, MOD = 1e9 + 7;

int win[N][N], rev[N][N], dp[1 << N], p[1 << N];

int add(int a, int b) {
	a += b;
	return a >= MOD ? a - MOD : a;
}

int sub(int a, int b) {
	a -= b;
	return a < 0 ? a + MOD : a;
}

int mul(int a, int b) {
	return (a * 1ll * b) % MOD;
}

int pow(int a, int n) {
	if (n == 0) return 1;
	int b = pow(a, n / 2);
	b = mul(b, b);
	return n & 1 ? mul(b, a) : b;
}

int main() {
#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;
	vi a(n);
	forn (i, n)
		cin >> a[i];
	forn (i, n)
		forn (j, n) {
			win[i][j] = mul(a[i], pow(a[i] + a[j], MOD - 2));
			rev[i][j] = pow(win[i][j], MOD - 2);
		}
	int ans = 0;
	forab (mask, 1, 1 << n) {
		dp[mask] = 1;
		for (int s = mask; s > 0; s = (s - 1) & mask) {
			if (s == mask) 
				continue;
			int rem = mask ^ s;
			int coef = 1;
			if ((rem & (rem - 1)) == 0) {
				int ind = 0;
				for (int i = 0; i < n; i++)
					if (rem & (1 << i)) {
						ind = i;
						break;
					}
				for (int i = 0; i < n; i++) 
					if (s & (1 << i)) {
						coef = mul(coef, win[i][ind]);
					}
			} else {
				int bit = rem ^ (rem & (rem - 1));
				int ind = 0;
				forn (i, n)
					if (1 << i == bit) {
						ind = i;
						break;
					}
				int oldS = s | bit;
				coef = p[oldS];
				forn (i, n)
					if ((mask & (1 << i))) {
						if (s & (1 << i))
							coef = mul(coef, win[i][ind]);
					 	if ((oldS & (1 << i)) == 0)
							coef = mul(coef, rev[ind][i]);
					}
			}
			p[s] = coef;
			dp[mask] = sub(dp[mask], mul(dp[s], coef));
		}
		int prob = 1, cnt = 0;
		forn (i, n) {
			if ((mask & (1 << i)) == 0)
				continue;
			cnt++;
			forn (j, n) {
				if (mask & (1 << j))
					continue;
				prob = mul(prob, win[i][j]);
			}
		}
		ans = add(ans, mul(cnt, mul(dp[mask], prob)));
	}
	cout << ans << "\n";
	return 0;
}