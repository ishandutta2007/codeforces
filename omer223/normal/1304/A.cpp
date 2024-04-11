#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
	int t, a, b, x, y;
	cin >> t;
	while (t--) {
		cin >> x >> y >> a >> b;
		if ((y - x) % (a + b) != 0) cout << -1 << endl;
		else cout << (y - x) / (a + b) << endl;
	}
}