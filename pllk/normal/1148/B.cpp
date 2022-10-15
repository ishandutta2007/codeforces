#include <iostream>

using namespace std;

int n, m, ta, tb, k;
int a[202020];
int b[202020];

int main() {
	cin >> n >> m >> ta >> tb >> k;
	if (k >= n || k >= m) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	int j = 1;
	int h = 0;
	for (int i = 0; i <= n; i++) {
		if (i > k) break;
		while (j <= m && a[i+1]+ta > b[j]) j++;
		if (j == m+1) {
			cout << "-1\n";
			return 0;
		}
		int u = k-i;
		if (j+u > m) {
			cout << "-1\n";
			return 0;
		}
		h = max(h,b[j+u]+tb);
	}
	cout << h << "\n";
}