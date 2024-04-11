#include <bits/stdc++.h>
using namespace std;

int main() {
	int i, j, n;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			cin >> n;
			if (n == 1) goto calc;
		}
	}
	calc:
		cout << abs(i - 2) + abs(j - 2);
}