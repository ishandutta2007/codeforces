#include <iostream>

using namespace std;

int a[2222];
int s[27][2222];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int c = 1; c <= 26; c++) {
			for (int i = 1; i <= n; i++) {
				s[c][i] = s[c][i-1]+(a[i]==c);
			}
		}
		int pp = 0;
		for (int c = 1; c <= 26; c++) {
			pp = max(pp,s[c][n]);
			int l = 1, r = n;
			int f = 0;
			while (true) {
				while (a[l] != c && l != n) l++;
				while (a[r] != c && r != 1) r--;
				if (l >= r) break;
				f += 2;
				int p = 0;
				for (int d = 1; d <= 26; d++) {
					int u = s[d][r-1]-s[d][l];
					if (u > p) p = u;
				}
				pp = max(pp,f+p);
				l++; r--;
			}
		}
		cout << pp << "\n";
	}
}