#include <iostream>

using namespace std;

int r[333][333];
int n, k;

void fill(int x) {
	for (int y = 1; y <= n && k; y++) {
		r[y][x] = 1;
		x++;
		if (x == n+1) x = 1;
		k--;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) r[i][j] = 0;
		}
		for (int i = 1; i <= n; i++) {
			fill(i);
		}
		int a1 = n, a2 = 0, b1 = n, b2 = 0;
		for (int i = 1; i <= n; i++) {
			int c;
			c = 0;
			for (int j = 1; j <= n; j++) c += r[i][j];
			a1 = min(a1,c);
			a2 = max(a2,c);
			c = 0;
			for (int j = 1; j <= n; j++) c += r[j][i];
			b1 = min(b1,c);
			b2 = max(b2,c);
		}
		cout << (a2-a1)*(a2-a1)+(b2-b1)*(b2-b1) << "\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << r[i][j];
			}
			cout << "\n";
		}
	}
}