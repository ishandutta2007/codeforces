#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m;
string temp;
vector<vector<char>> c;

int main() {
	fast;
	cin >> n >> m;
	c.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		if ((i + j) & 1)
			c[i][j] = 'B';
		else
			c[i][j] = 'W';
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < m; j++)
			if (temp[j] == '-')
				c[i][j] = '-';
	}
	for (auto &i : c) {
		for (auto &j : i) cout << j;
		cout << endl;
	}
}