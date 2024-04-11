#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef long long ll;

int T, n, m;
char a[510][510];

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> a[i][j];
		for (int i = 1; i <= n; i += 3)
			for (int j = 1; j <= m; j++)
				a[i][j] = 'X';
		for (int i = 1; i + 3 <= n; i += 3) {
			int flag = false;
			for (int j = 1; j <= m; j++) {
				if (a[i + 1][j] == 'X' || a[i + 2][j] == 'X') {
					a[i + 1][j] = a[i + 2][j] = 'X', flag = 1;
					break; 
				}
			}
			if (flag == false)
				a[i + 1][1] = a[i + 2][1] = 'X';
		}
		if (n % 3 == 0) {
			for (int j = 1; j <= m; j++) {
				if (a[n - 1][j] == 'X' || a[n][j] == 'X')
					a[n - 1][j] = a[n][j] = 'X'; 
			}
		}
		for (int i = 1; i <= n; i++, cout << "\n")
			for (int j = 1; j <= m; j++)
				cout << a[i][j];
	}
	return 0;
}