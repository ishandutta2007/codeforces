#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m;
	cin >> m;

	int h1, a1, x1, y1;
	cin >> h1 >> a1 >> x1 >> y1;

	int h2, a2, x2, y2;
	cin >> h2 >> a2 >> x2 >> y2;

	vector<pair<int, int>> visited1(m);
	for (int i = h1, j = 0; !visited1[i].second; i = ((long long)x1 * i + y1) % m, j++) {
		if (!visited1[i].first)
			visited1[i].first = j;
		else visited1[i].second = j;
	}

	vector<pair<int, int>> visited2(m);
	for (int i = h2, j = 0; !visited2[i].second; i = ((long long)x2 * i + y2) % m, j++) {
		if (!visited2[i].first)
			visited2[i].first = j;
		else visited2[i].second = j;
	}

	if (!visited1[a1].first || !visited2[a2].first) {
		return cout << "-1\n", 0;
	}

	if (visited1[a1].first == visited2[a2].first) {
		return cout << visited1[a1].first << '\n', 0;
	}

	long long turn1 = visited1[a1].first, turn2 = visited2[a2].first;
	for (int i = 0; i < 2000000; i++) {
		long long now1 = turn1, now2 = turn2;
		if (visited1[a1].second)
			now1 = turn1 + visited1[a1].second - visited1[a1].first;
		if (visited2[a2].second)
			now2 = turn2 + visited2[a2].second - visited2[a2].first;
		if (now1 <= now2) {
			turn1 = now1;
		} else {
			turn2 = now2;
		}
		if (turn1 == turn2) {
			return cout << turn1 << '\n', 0;
		}
	}

	cout << "-1\n";
	return 0;
}