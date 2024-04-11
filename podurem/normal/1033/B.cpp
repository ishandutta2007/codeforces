#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;
typedef long double ld;

using namespace std;

const int dd = (int)1e5 + 7;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		if (a - b != 1) {
			cout << "NO\n";
			continue;
		}
		ll c = a + b;
		bool f = true;
		for (int i = 2; 1ll * i * i <= c; ++i) {
			if (c % i == 0) {
				f = false;
			}
		}
		cout << (f ? "YES\n" : "NO\n");
	}
	return 0;
}