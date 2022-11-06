#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, n, p = 0, q = INT_MIN;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		p -= a;
		p += b;
		q = max(q, p);
	}
	cout << q;
}