#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, m;
string s[100];

int findleft() {
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (s[j][i] == 'B') return i;
	return -1;
}

int findright() {
	for (int i = m - 1; i >= 0; i--) for (int j = 0; j < n; j++) if (s[j][i] == 'B') return i;
	return -1;
}

int findup() {
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (s[i][j] == 'B') return i;
	return -1;
}

int finddown() {
	for (int i = n - 1; i >= 0; i--) for (int j = 0; j < m; j++) if (s[i][j] == 'B') return i;
	return -1;
}

int count() {
	int rtn = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (s[i][j] == 'B') rtn++;
	return rtn;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	int l = findleft(), r = findright(), u = findup(), d = finddown();
	if (l == -1) {
		cout << 1 << endl;
		return 0;
	}
	int size = max(r - l, d - u) + 1;
	if (size > n || size > m) {
		cout << -1 << endl;
		return 0;
	}
	cout << size * size - count() << endl;
	return 0;
}