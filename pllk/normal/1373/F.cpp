#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll a[1222333];
ll b[1222333];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> b[i];
		for (int i = 1; i <= n; i++) cin >> a[i+1];
		a[1] = a[n+1];
		bool ok = false;
		int c = 0;
		for (int h = 1; h <= 5; h++) {
			for (int i = 1; i <= n; i++) {
				int i1 = i;
				int i2 = i+1;
				if (i2 > n) i2 = 1;
				if (a[i1] < b[i1]) {
					ll d = b[i1]-a[i1];
					if (d > a[i2]) goto skip;
					b[i1] -= d;
					a[i2] -= d;
					c = 0;
				} else c++;
			}
			if (c > n) {
				ok = true; break;
			}
		}
		skip:
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
}