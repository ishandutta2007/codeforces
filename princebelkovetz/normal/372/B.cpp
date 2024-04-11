#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

int mp[41][41][41][41];
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int n, m, q; cin >> n >> m >> q;
	vector <string> a(n);
	for (auto& x : a) cin >> x;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int x = 0; x < n - i; ++x) {
				for (int y = 0; y < m - j; ++y) {
					if (!i and !j) {
						if (a[x][y] == '0') mp[x][y][x][y] = 1;
						else mp[x][y][x][y] = 0;
					}
					else {
						if (j) {
							if (mp[x][y][x + i][y + j - 1] and mp[x][y + j][x + i][y + j]) mp[x][y][x + i][y + j] = 1;
							else mp[x][y][x + i][y + j] = 0;
						}
						else if (i) {
							if (mp[x][y][x + i - 1][y + j] and mp[x + i][y][x + i][y + j]) mp[x][y][x + i][y + j] = 1;
							else mp[x][y][x + i][y + j] = 0;
						}
					}
				}
			}
		}
	}
	for (int a = n - 1; a > 0; --a) {
		for (int b = 0; b < m; ++b) {
			for (int c = a; c < n; ++c) {
				for (int d = b; d < m; ++d) {
					mp[a - 1][b][c][d] += mp[a][b][c][d];
				}
			}
		}
	}
	for (int a = 0; a < n; ++a) {
		for (int b = m - 1; b > 0; --b) {
			for (int c = a; c < n; ++c) {
				for (int d = b; d < m; ++d) {
					mp[a][b - 1][c][d] += mp[a][b][c][d];
				}
			}
		}
	}
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < m; ++b) {
			for (int c = a; c < n - 1; ++c) {
				for (int d = b; d < m; ++d) {
					mp[a][b][c + 1][d] += mp[a][b][c][d];
				}
			}
		}
	}
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < m; ++b) {
			for (int c = a; c < n; ++c) {
				for (int d = b; d < m - 1; ++d) {
					mp[a][b][c][d + 1] += mp[a][b][c][d];
				}
			}
		}
	}
	while (q--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		cout << mp[--a][--b][--c][--d] << '\n';
	}

	
}