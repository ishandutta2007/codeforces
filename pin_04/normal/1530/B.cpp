#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {
	if (a > b) {a = b; return true;} return false;
}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {
	if (a < b) {a = b; return true;} return false;
}
const int N = 105;
const int oo = 1e9;

int a[N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int r, c;
		cin >> r >> c;
		for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			a[i][j] = 0;

		for (int i = 1; i <= c; i += 2) 
			a[1][i] = a[r][i] = 1;

		for (int i = 2; i < r; i++) {
			if (!a[i - 1][1] && !a[i + 1][1])
				a[i][1] = 1;
			if (!a[i - 1][c] && !a[i + 1][c] 
				&& !a[i - 1][c - 1] && !a[i + 1][c - 1])
				a[i][c] = 1;
		}

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++)
				cout << a[i][j];
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}