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

const int N = 105;

int a[N][N];

void print(int k) {
	cout << k << "\n";
	forn (i, k) {
		forn (j, k)
			cout << (a[i][j] ? 'o' : '.');
		cout << "\n";
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
	cin >> n;
	if (n == 2) {
		cout << "-1\n";
		return 0;
	}
	for (int k = 1; k <= n; k++) {
		if (k * k >= n) {
			if (k * k == n + 2) {
				forn (i, k + 1)
					forn (j, k + 1)
						a[i][j] = 1;
				forn (i, k + 1)
					a[0][i] = a[i][k] = 0;
				a[0][0] = a[k][k] = 1;
				a[1][k - 2] = a[1][k - 1] = 0;
				a[2][k - 2] = a[2][k - 1] = 0;
				print(k + 1);		
			} else {
				forn (i, k)
					forn (j, k)
						a[i][j] = 1;
				if (k * k != n) {
					a[0][k - 1] = 0;
					if ((k * k - n) % 2 == 0)
						a[1][k - 2] = 0;
					int l = (k * k - n - 1) / 2;
					for (int j = 1; j <= l; j++)
						a[0][k - 1 - j] = a[j][k - 1] = 0;
				}
				print(k); 
			}
			return 0;
		}
	}
	
	return 0;
}