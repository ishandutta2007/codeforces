#include <iostream>

using namespace std;

typedef long long ll;

#define M 998244353

int n, m;
int a[202020];
int b[202020];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	int r = 1222333444;
	int j = n+1;
	ll u = 1;
	for (int i = m; i >= 1; i--) {
		if (j == 1) {u = 0; break;}
		while (j-1 >= 1 && r > b[i]) {
			j--;
			r = min(r,a[j]);
		}
		if (r != b[i]) {u = 0; break;}
		int x = j;
		while (j-1 >= 1 && a[j-1] >= b[i]) {
			j--;
		}
		if (i == 1 && j != 1) {u = 0; break;}
		if (i == 1) x = 1;
		u = u*(x-j+1)%M;
	}
	cout << u << "\n";
}