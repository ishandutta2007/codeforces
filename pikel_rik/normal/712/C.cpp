#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, y;
	cin >> x >> y;

	int ans = 0;
	array<int, 3> sides = {y, y, y};

	while (sides[0] != x || sides[1] != x || sides[2] != x) {
		if (sides[0] <= sides[1] && sides[0] <= sides[2]) {
			sides[0] = min(x, sides[1] + sides[2] - 1);
		} else if (sides[1] <= sides[0] && sides[1] <= sides[2]) {
			sides[1] = min(x, sides[0] + sides[2] - 1);
		} else {
			sides[2] = min(x, sides[0] + sides[1] - 1);
		}
		ans += 1;
	}
	cout << ans << '\n';
	return 0;
}