#include <iostream>

using namespace std;

#define K 21
#define P (1<<K)

int x[1222333];
int n;
int dd[P][2];
int p;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		dd[x[i]][1] = dd[x[i]][0];
		dd[x[i]][0] = i;
	}
	for (int k = 0; k < K; k++) {
		for (int i = P-1; i >= 0; i--) {
			if (~i&(1<<k)) {
				int u = dd[i^(1<<k)][0];
				if (u > dd[i][0]) {
					dd[i][1] = dd[i][0];
					dd[i][0] = u;
				} else if (u > dd[i][1]) {
					dd[i][1] = u;
				}
				u = dd[i^(1<<k)][1];
				if (u > dd[i][1]) {
					dd[i][1] = u;
				}
			}
		}
	}
	for (int i = 1; i+2 <= n; i++) {
		int u = x[i];
		int g = 0;
		for (int j = K-1; j >= 0; j--) {
			if (u&(1<<j)) continue;
			if (dd[g|(1<<j)][1] > i) g |= (1<<j);
		}
		p = max(p,u|g);
	}
	cout << p << "\n";
}