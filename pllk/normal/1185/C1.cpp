#include <iostream>

using namespace std;

int n, m;
int t[202020];
int c[111];
int s;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		int u = s;
		int r = m-t[i];
		int d = 0;
		for (int k = 100; k >= 1 && u > r; k--) {
			int h = min(c[k],(u-r+k-1)/k);
			d += h;
			u -= h*k;
		}
		cout << d << " ";
		s += t[i];
		c[t[i]]++;
	}
	cout << "\n";
}