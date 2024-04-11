#include <bits/stdc++.h>

using namespace std;

bool check(int u) {
	int sum = 0;
	while (u) {
		sum += u % 10;
		u /= 10;
	}
	return sum == 10;
}

int main() {
	int k;
	cin >> k;
	int u = 0;
	while (1) {
		u++;
		if (check(u)) {
			k--;
		}
		if (k == 0) {
			cout << u << endl;
			return 0;
		}
	}
	return 0;
}