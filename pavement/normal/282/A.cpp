#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x = 0;
	char a, b, c;
	cin >> n;
	while (n--) {
		cin >> a >> b >> c;
		if (b == '+') x++;
		else x--;
	}
	cout << x;
}