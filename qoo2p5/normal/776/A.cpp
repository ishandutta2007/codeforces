#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = 1e-8;
const int MOD = (int) 1e9 + 7;

#define sz(x) (int) x.size()

void run() {
	string a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << a << " " << b << "\n";
		string x, y;
		cin >> x >> y;
		if (x == a) {
			a = y;
		} else {
			b = y;
		}
	}
	cout << a << " " << b << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	run();
	return 0;
}