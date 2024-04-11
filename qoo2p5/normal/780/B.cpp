#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const int MOD = (int) 1e9 + 7;
const ll LINF = (ll) 1e18 + 123;

#define sz(x) (int) (x).size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

void run();

int main() {
	cout << setprecision(15) << fixed;
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#endif
	run();
	return 0;
}

// == BEGIN SOLUTION == //

const int N = (int) 1e5 + 123;

int n;
ld x[N], v[N];

ld calc(ld p) {
	ld res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, abs(p - x[i]) / v[i]);
	}
	return res;
}

void run() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	ld left = -INF;
	ld right = INF;
	
	for (int it = 0; it < 150; it++) {
		ld x1 = left + (right - left) / 3;
		ld x2 = right - (right - left) / 3;
		
		if (calc(x1) < calc(x2)) {
			right = x2;
		} else {
			left = x1;
		}
	}
	
	cout << calc(left) << "\n";
}