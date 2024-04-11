#include <iostream>

using namespace std;

int a[202020];
int c[222];
int u[222];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int pp = 0;
		for (int i = 1; i <= 200; i++) c[i] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			c[a[i]]++;
			pp = max(pp,c[a[i]]);
		}
		for (int h = 1; h <= 200; h++) {
			for (int i = 1; i <= 200; i++) u[i] = c[i];
			int l = 1, r = n;
			int f = 0;
			while (true) {
				while (l <= n && a[l] != h) {
					u[a[l]]--; l++;
				}
				while (r >= 1 && a[r] != h) {
					u[a[r]]--; r--;
				}
				f += 2;
				if (l >= r) break;
				int p = 0;
				for (int i = 1; i <= 200; i++) if (i != h) p = max(p,u[i]);
				pp = max(pp,p+f);
				l++; r--;
			}
		}
		cout << pp << "\n";
	}
}