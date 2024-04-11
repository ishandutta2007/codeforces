#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 149;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, dp[2][10001];
string s;
vector<string> a;
unordered_map<int, int> h[1001];

char lo(char c) {
	if (c < 'a') return char(c + 32);
	return c;
}

void print(int at) {
	if (at == 0) return;
	print(at - (int)a[dp[1][at]].size());
	cout << a[dp[1][at]] << " ";
}

int main() {
	fast;
	cin >> n >> s >> m;
	a.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		ll val = 0;
		for (int j = 0; j < a[i].size(); j++)
			val = (val * hs + lo(a[i][j])) % md;
		h[a[i].size()][val] = i;
	}

	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		ll val = 0;
		int good = -1;
		for (int j = i; j >= max(0, i - 999) && good == -1; j--) {
			val = (val * hs + s[j]) % md;
			if (dp[0][j] && h[i - j + 1].find(val) != h[i - j + 1].end())
				good = h[i - j + 1][val];
		}
		if (good == -1) dp[0][i + 1] = 0, dp[1][i + 1] = -1;
		else dp[0][i + 1] = 1, dp[1][i + 1] = good;
	}

	print(n);
}