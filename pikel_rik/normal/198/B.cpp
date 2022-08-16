#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, k;
string s[2];

bool visited[2][N];
int lvl[2][N];

bool bfs() {
	queue<pair<int, int>> q;
	q.emplace(0, 0);
	visited[0][0] = true;
	lvl[0][0] = 0;

	while (!q.empty()) {
		auto [i, j] = q.front();
		q.pop();

		int water_level = lvl[i][j];

		if (j + k >= n) {
			return true;
		}
		if (j + k < n && s[1 - i][j + k] != 'X' && !visited[1 - i][j + k]) {
			visited[1 - i][j + k] = true;
			lvl[1 - i][j + k] = 1 + water_level;
			q.emplace(1 - i, j + k);
		}
		if (j + 1 < n && s[i][j + 1] != 'X' && !visited[i][j + 1]) {
			lvl[i][j + 1] = 1 + water_level;
			visited[i][j + 1] = true;
			q.emplace(i, j + 1);
		}
		if (j - 1 > water_level && s[i][j - 1] != 'X' && !visited[i][j - 1]) {
			lvl[i][j - 1] = 1 + water_level;
			visited[i][j - 1] = true;
			q.emplace(i, j - 1);
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	cin >> s[0] >> s[1];

	cout << (bfs() ? "YES" : "NO") << '\n';
	return 0;
}