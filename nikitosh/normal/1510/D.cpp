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

const ll INF = 2e18;

ll ans = INF + 1;
int d, mult = 1;
int cnt[10], curCnt[10];
vi v[10];

ll mul(ll a, int b) {
	if (INF / a < b)
		return INF;
	return min(INF, a * b);
}

void gen(const vi& dig, int k, ll cur) {
	if (k == sz(dig)) {
		if (cur < ans && (cur % 10 * d) % 10 == mult) {
			if (d % 2 == 0) {
				bool ok = 0;
				for (int i = 2; i < 10; i += 2)
					if (curCnt[i] != sz(v[i]))
						ok = 1;
				if (!ok)
					return;
			}
			ans = cur;
			forn (j, 10)
				cnt[j] = curCnt[j];
		}
		return;
	}
	if (dig[k] == 1) {
		curCnt[1] = 0;
		gen(dig, k + 1, cur);
	} else {
		ll curRes = cur;
		forn (j, min(sz(v[dig[k]]) + 1, 4)) {
			curCnt[dig[k]] = j;
			gen(dig, k + 1, curRes);
			if (j == min(sz(v[dig[k]]) + 1, 4) - 1)
				break;
			curRes = mul(curRes, v[dig[k]][j]);
			if (curRes == INF)
				break;
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n >> d;
	vi a(n);
	forn (i, n) {
		cin >> a[i];
		v[a[i] % 10].pb(a[i]);
	}
	sort(all(a));
	forn (i, 10)
		sort(all(v[i]));
	if (d == 0) {
		if (!v[0].empty() || (!v[5].empty() && (sz(v[2]) + sz(v[4]) + sz(v[6]) + sz(v[8])) > 0)) {
			cout << n << "\n";
			forn (i, n)
				cout << a[i] << " ";
			cout << "\n";
		} else {
			cout << "-1\n";
		}
		return 0;
	}
	if (d == 5) {
		if (!v[5].empty()) {
			vi u;
			forn (i, n)
				if ((a[i] % 10) % 2 != 0)
					u.pb(a[i]);
			cout << sz(u) << "\n";
			for (int k : u)
				cout << k << " ";
			cout << "\n";
		} else {
			cout << "-1\n";
		}
		return 0;
	}
	vi digits = {1, 3, 7, 9};
	if (d % 2 == 0) {
		digits = {1, 2, 3, 4, 6, 7, 8, 9}; 
	}
	mult = 1;
	for (int dig : digits) 
		forn (j, sz(v[dig]))
			mult = (mult * dig) % 10;
	gen(digits, 0, 1);
	vi u;
	forn (i, sz(digits)) {
		int dig = digits[i];
		forab (j, cnt[dig], sz(v[dig])) 
			u.pb(v[dig][j]);
	}
	if (ans == INF + 1 || sz(u) == 0) {
		cout << "-1\n";
		return 0;
	}
	sort(all(u));
	cout << sz(u) << "\n";
	for (int k : u)
		cout << k << " ";
	cout << "\n";
	
	return 0;
}