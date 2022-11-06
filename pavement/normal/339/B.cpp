#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long n, m, i, pos = 1, t = 0;
	cin >> n >> m;
	while (m--) {
		cin >> i;
		if (pos > i) t += (n + i) - pos;
		else if (pos < i) t += i - pos;
		pos = i;
	}
	cout << t;
}