#include <iostream>

using namespace std;

typedef long long ll;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int s = 1;
	int c1 = 1, c2 = 0;
	ll t1 = 0, t2 = 0;
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		if (u < 0) s = -s;
		if (s > 0) {
			t1 += c1;
			t2 += c2;
			c1++;
		} else {
			t1 += c2;
			t2 += c1;
			c2++;
		}
	}
	cout << t2 << " " << t1 << "\n";
}