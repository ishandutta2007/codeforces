#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, k;
int a[100][100];
int c[100];
int d[11][100];

int work() {
	for (int i = 0; i < n; i++)
		c[i] = rand() & 1;

	for (int t = 1; t <= k; t++) {
		for (int i = 0; i < n; i++) {
			d[t][i] = md;
			for (int j = 0; j < n; j++)
				if (c[i] ^ c[j]) {
					if (d[t][i] > d[t - 1][j] + a[j][i])
						d[t][i] = d[t - 1][j] + a[j][i];
				}
		}
	}
	return d[k][0];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	srand(12132); // you dare fucking hack this
	cin >> n >> k;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		cin >> a[i][j];
	d[0][0] = 0;
	for (int i = 1; i < n; i++)
		d[0][i] = md;
	int ans = md;
	for (int t = 0; t < 5000; t++)
		ans = min(ans, work());
	cout << ans << '\n';
}