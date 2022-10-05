#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
using namespace std;

int n, m;
string s[100];

bool checkrow() {
	if (n % 3) return false;
	for (int i = 0; i < n / 3; i++) for (auto j : s[i])
		if (j != s[0][0]) return false;
	for (int i = n / 3; i < 2 * n / 3; i++) for (auto j : s[i])
		if (j != s[n / 3][0]) return false;
	for (int i = 2 * n / 3; i < n; i++) for (auto j : s[i])
		if (j != s[2 * n / 3][0]) return false;
	if (s[0][0] == s[n / 3][0] || s[0][0] == s[2 * n / 3][0] || s[n / 3][0] == s[2 * n / 3][0]) return false;
	return true;
}

bool checkcol() {
	if (m % 3) return false;
	for (int i = 0; i < m / 3; i++) for (int j = 0; j < n; j++)
		if (s[j][i] != s[0][0]) return false;
	for (int i = m / 3; i < 2 * m / 3; i++) for (int j = 0; j < n; j++)
		if (s[j][i] != s[0][m / 3]) return false;
	for (int i = 2 * m / 3; i < m; i++) for (int j = 0; j < n; j++)
		if (s[j][i] != s[0][2 * m / 3]) return false;
	if (s[0][0] == s[0][m / 3] || s[0][0] == s[0][2 * m / 3] || s[0][m / 3] == s[0][2 * m / 3]) return false;
	return true;
}

int main() {
	fast;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	if (checkrow() || checkcol()) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}