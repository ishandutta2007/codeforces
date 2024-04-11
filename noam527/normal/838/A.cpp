#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t[2500][2500], o[2501][2501], n, m;
vector<int> primes;
char c;

void sieve() {
	vector<bool> s(2525, true);
	int i;
	for (i = 2; i * i < s.size(); i++)
		if (s[i]) {
			primes.push_back(i);
			for (int j = i * i; j < s.size(); j += i) s[j] = false;
		}
	for (; i < s.size(); i++) if (s[i]) primes.push_back(i);
}

int query(int k, int t, int l) {
	int b = min(n - 1, t + k - 1), r = min(m - 1, l + k - 1);
	t++, l++, b++, r++;
	int rtn = o[b][r] - o[t - 1][r] - o[b][l - 1] + o[t - 1][l - 1];
	return min(rtn, k * k - rtn);
}

int check(int k) {
	int rtn = 0;
	for (int i = 0; i < n; i += k) for (int j = 0; j < m; j += k) rtn += query(k, i, j);
	return rtn;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	sieve();
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> c, t[i][j] = c - '0';
	for (int i = 0; i < n; i++) o[i][0] = 0;
	for (int i = 0; i < m; i++) o[0][i] = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) o[i][j] = o[i - 1][j] + o[i][j - 1] - o[i - 1][j - 1] + t[i - 1][j - 1];
	int mn = 2e9;
	for (auto i : primes) mn = min(mn, check(i));
	cout << mn << endl;
}