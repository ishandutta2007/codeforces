#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i, p, g = 1;
	cin >> n;
	cin >> p;
	n--;
	while (n--) {
		cin >> i;
		if (i != p) g++;
		p = i;
	}
	cout << g;
}