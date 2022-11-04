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

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);


	int n, bx;
	cin >> n >> bx;
	ull x = 0;
	for (int i = 0; i < n; i++) {
		ull f;
		cin >> f;
		x *= bx;
		x += f;
	}

	int m, by;
	cin >> m >> by;
	ull y = 0;
	for (int i = 0; i < m; i++) {
		ull f;
		cin >> f;
		y *= by;
		y += f;
	}

	if (x < y) {
		cout << "<\n";
	} else if (x == y) {
		cout << "=\n";
	} else {
		cout << ">\n";
	}

    return 0;
}