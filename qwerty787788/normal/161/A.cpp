#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m, x, y;
int a[100000], b[100000];
int to[100000];
int sum = 0;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m >> x >> y;
	for (int i = 0; i < n; i++) {
		scanf("%d ", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d ", &b[i]);
	}
	int xx = 0;
	for (int i = 0; i < n; i++) {
		while (xx < m && b[xx] < a[i] - x) {
			xx++;
		}
		if (xx < m && a[i] - x <= b[xx] && a[i] + y >= b[xx]) {
			to[i] = xx + 1;
			sum++;
			xx++;
		}
	}
	printf("%d\n", sum);
	for (int i = 0; i < n; i++) {
		if (to[i] != 0) {
			printf("%d %d\n", i+1, to[i]);
		}
	}
}