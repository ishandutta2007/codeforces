#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

int n, p, q;
string s;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	cin >> n >> p >> q >> s;

	for (int a = 0; a <= n; a++) {
		int rest = n - a * p;
		if (rest < 0 || rest % q != 0) {
			continue;
		}

		int b = rest / q;

		cout << a + b << "\n";

		for (int i = 0; i < a; i++) {
			int start = i * p;
			cout << s.substr(start, p) << "\n";
		}

		for (int i = 0; i < b; i++) {
			int start = a * p + i * q;
			cout << s.substr(start, q) << "\n";
		}

		return 0;
	}

	cout << "-1\n";

    return 0;
}