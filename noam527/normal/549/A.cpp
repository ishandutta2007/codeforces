#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(char a, char b) { return a < b; }

int n, m, cnt = 0;
vector<char> f(4);
vector<vector<char>> t(50, vector<char>(50));

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> t[i][j];
	for (int i = 0; i < n - 1; i++) for (int j = 0; j < m - 1; j++) {
		f[0] = t[i][j], f[1] = t[i][j + 1], f[2] = t[i + 1][j], f[3] = t[i + 1][j + 1];
		sort(f.begin(), f.end(), cmp);
		if (f[0] == 'a' && f[1] == 'c' && f[2] == 'e' && f[3] == 'f') cnt++;
	}
	cout << cnt << endl;
}