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

int printOr(int i, int j) {
	cout << "or " << i + 1 << " " << j + 1 << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}

int printAnd(int i, int j) {
	cout << "and " << i + 1 << " " << j + 1 << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}

int g(int x, int k) {
	return x & (1 << k);
}

int main() {
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	
	int n, k;
	cin >> n >> k;
	int or01 = printOr(0, 1), or02 = printOr(0, 2), or12 = printOr(1, 2);
	int and01 = printAnd(0, 1), and02 = printAnd(0, 2), and12 = printAnd(1, 2);
	vi a(n);
	for (int i = 0; i < 30; i++) {
		if (g(and01, i) && g(and02, i)) {
			a[0] |= (1 << i), a[1] |= (1 << i), a[2] |= (1 << i);
		} else if (g(and01, i) && g(and02, i) == 0) {
			a[0] |= (1 << i), a[1] |= (1 << i);
		} else if (g(and02, i) && g(and01, i) == 0) {
			a[0] |= (1 << i), a[2] |= (1 << i);
		} else if (g(and12, i) && g(and01, i) == 0) {
			a[1] |= (1 << i), a[2] |= (1 << i);
		} else if (g(or01, i) && g(or02, i) && g(or12, i) == 0) {
			a[0] |= (1 << i);
		} else if (g(or01, i) && g(or12, i) && g(or02, i) == 0) {
			a[1] |= (1 << i);
		} else if (g(or02, i) && g(or12, i) && g(or01, i) == 0) {
			a[2] |= (1 << i);
		}
	}
	int full = (1ll << 31) - 1;
	forab (i, 3, n) {
		int x = printOr(0, i), y = printAnd(0, i);
		a[i] = y | ((x ^ y) & (full - a[0]));
	}
	sort(all(a));
	cout << "finish " << a[k - 1] << endl;
	fflush(stdout);

	return 0;
}