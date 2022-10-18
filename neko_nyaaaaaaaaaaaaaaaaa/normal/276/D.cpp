#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);

      ll a, b;
	cin >> a >> b;
	for (int i = 63; i>=0; --i) {
		if ((a&(1LL<<i)) != (b&(1LL<<i))) {
			cout << (1LL<<i) - 1 + (1LL<<i) << "\n";
			return 0;
		}
	}
	cout << "0\n";

	return 0;
}