#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, h, w = 0, i;
	cin >> n >> h;
	while (n--) {
		cin >> i;
		if (i > h) w += 2;
		else w++;
	}
	cout << w;
}