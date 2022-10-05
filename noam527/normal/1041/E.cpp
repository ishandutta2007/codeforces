#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
using namespace std;

int n;
vector<int> b;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	b.resize(n, 0);
	for (int i = 0, x, y; i < n - 1; i++) {
		cin >> x >> y;
		if (y != n) finish("NO");
		b[--x]++;
	}
	for (int i = 0, sum = 0; i < n; i++) {
		sum += b[i];
		if (i + 1 < sum) finish("NO");
	}
	cout << "YES" << endl;
	int nxt = 0, prev;
	for (int i = 0; i < n; i++) {
		prev = n - 1;
		for (int j = 0; j < b[i]; j++) {
			if (j + 1 == b[i]) {
				cout << prev + 1 << " " << i + 1 << '\n';
			}
			else {
				while (b[nxt]) nxt++;
				cout << prev + 1 << " " << nxt + 1 << '\n';
				prev = nxt++;
			}
		}
	}
}