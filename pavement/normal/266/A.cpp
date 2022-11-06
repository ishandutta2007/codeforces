#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p = 0;
	char c, prev;
	cin >> n >> prev;
	n--;
	while (n--) {
		cin >> c;
		if (c == prev) p++;
		prev = c;
	}
	cout << p;
}