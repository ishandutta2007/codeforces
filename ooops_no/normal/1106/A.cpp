/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

using namespace std;
typedef long long ll;

ll n;

bool check(int i, int j) {
	return i >= 0 && j >= 0 && j < n && i < n;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(20);
	cin >> n;
	vector<vector<char>> g(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (g[i][j] == 'X') {
				if (check(i - 1, j - 1) && check(i - 1, j + 1) && check(i + 1, j + 1) && check(i + 1, j - 1)) {
					if (g[i - 1][j - 1] == 'X' && g[i - 1][j + 1] == 'X' && g[i + 1][j + 1] == 'X' && g[i + 1][j - 1] == 'X') {
						cnt++;
					}
				}
			}
		}
	}
	cout << cnt;
}