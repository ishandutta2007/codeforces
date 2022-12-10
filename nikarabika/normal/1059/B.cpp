//sobskdrbhvk
//remeber... ):(
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 10;
string sig[maxn];
int a[3][3];
bool mark[maxn][maxn];
int n, m;

int main() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			a[i][j] = (i != 1 or j != 1);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> sig[i];
		for (auto &c : sig[i])
			c = (c == '#');
	}
	for (int i = 0; i + 2 < n; i++)
		for (int j = 0; j + 2 < m; j++) {
			int cnt = 0;
			for (int ii = 0; ii < 3; ii++)
				for (int jj = 0; jj < 3; jj++)
					cnt += a[ii][jj] & sig[i + ii][j + jj];
			if (cnt != 8) continue;
			for (int ii = 0; ii < 3; ii++)
				for (int jj = 0; jj < 3; jj++)
					if (a[ii][jj])
						mark[i + ii][j + jj] = true;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (sig[i][j] and !mark[i][j])
				return cout << "NO", 0;
	cout << "YES";
	return 0;
}