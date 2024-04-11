#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, z = 0, o = 0;
	char c;
	cin >> n;
	while (n--) {
		cin >> c;
		if (c == '1') o++;
		else z++;
	}
	cout << abs(z - o);
}