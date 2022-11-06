#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, u = 0, c = 0, i;
	cin >> n;
	while (n--) {
		cin >> i;
		if (i == -1) {
			if (c == 0) u++;
			else c--;
		} else c += i;
	}
	cout << u;
}