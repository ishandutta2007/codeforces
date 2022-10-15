#include <iostream>

using namespace std;

typedef long long ll;

int n;
int a[404040];
int c[20];
ll u[20][20];

ll d[1<<20];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i]--;
		for (int j = 0; j < 20; j++) {
			if (a[i] != j) u[a[i]][j] += c[j];
		}
		c[a[i]]++;
	}
	for (int b = 1; b < (1<<20); b++) {
		d[b] = 1e18;
		for (int x = 0; x < 20; x++) {
			if (b&(1<<x)) {
				ll s = 0;
				for (int y = 0; y < 20; y++) {
					if (b&(1<<y)) s += u[x][y];
				}
				d[b] = min(d[b],d[b^(1<<x)]+s);
			}
		}
	}
	cout << d[(1<<20)-1] << "\n";
}