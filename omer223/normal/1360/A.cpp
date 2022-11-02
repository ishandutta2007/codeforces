#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, sm, bg;
		cin >> a >> b;
		sm = min(a, b);
		bg = max(a, b);
		int side = max(2 * sm, bg);
		cout << side * side << endl;
	}
	return 0;
}