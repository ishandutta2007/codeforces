#include <iostream>

using namespace std;

int v[33*33][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int k = n+m-1;
		for (int i = 1; i <= k; i++) v[i][0] = v[i][1] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int x;
				cin >> x;
				v[i+j-1][x]++;
			}
		}
		int u = 0;
		for (int i = 1; i <= k/2; i++) {
			u += min(v[i][0]+v[k-i+1][0],v[i][1]+v[k-i+1][1]);
		}
		cout << u << "\n";
	}
}