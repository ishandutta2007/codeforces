#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int a[2002][2002][2][2];
string s;
int k, d, siz, m;
int MOD = 1e9 + 7;
int dp(int u = 0)
{
	memset(a, 0, sizeof(a));
	int j = s.size() - 1;
	//
	//
	if (s[j] - '0' >= d)
		a[j][d % m][1][1] = 1;
	//
	for (int i = 0; i <= (s[j] - '0'); ++i)
		a[j][i % m][0][1] += (i != d);
	//
	//
	a[j][d % m][1][0] = 1;
	//
	for (int i = 0; i <= 9; ++i)
		a[j][i % m][0][0] += (i != d);
	int ten = 10;
	for (j = j - 1; j >= 0; --j, ten = ten * 10 % m) {
		//
		//
		if (s[j] - '0' >= d) {
			if (s[j] - '0' == d)
				for (int mod = 0; mod < m; ++mod)
					a[j][(mod + d * ten) % m][1][1] = (a[j][(mod + d * ten) % m][1][1] + a[j + 1][mod][0][1]) % MOD;
			else
				for (int mod = 0; mod < m; ++mod)
					a[j][(mod + d * ten) % m][1][1] = (a[j][(mod + d * ten) % m][1][1] + a[j + 1][mod][0][0]) % MOD;
		}
		//
		for (int mod = 0; mod < m; ++mod) {
			for (int i = 0; i < (s[j] - '0'); ++i)
				if (i != d)
					a[j][(mod + i * ten) % m][0][1] = (a[j][(mod + i * ten) % m][0][1] + a[j + 1][mod][1][0]) % MOD;
			if ((s[j] - '0') != d)
				a[j][(mod + ((s[j] - '0') * ten)) % m][0][1] = (a[j][(mod + ((s[j] - '0') * ten)) % m][0][1] + a[j + 1][mod][1][1]) % MOD;
		}
		//
		//
		for (int mod = 0; mod < m; ++mod)
			a[j][(mod + d * ten) % m][1][0] = (a[j][(mod + d * ten) % m][1][0] + a[j + 1][mod][0][0]) % MOD;
		//
		for (int i = 0; i <= 9; ++i) {
			if (i != d) {
				for (int mod = 0; mod < m; ++mod) {
					a[j][(mod + i * ten) % m][0][0] = (a[j][(mod + i * ten) % m][0][0] + a[j + 1][mod][1][0]) % MOD;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		ans = (ans + a[i][0][0][(i == 0)]) % MOD;
	}
	return ans % MOD;
}

bool is() {
	int y = 0;
	bool ok = true;
	for (int i = 0; i < s.size(); ++i) {
		y = (y * 10 + s[i] - '0') % m;
		if (((i & 1) && s[i] != (d + '0')) || ((!(i & 1)) && s[i] == (d + '0'))) {
			ok = false;
		} 
	}
	return (ok && (!y));
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	cin >> m;
	cin >> d;
	cin >> s;
	int ans = -dp(1);
	if (is()) {
		ans++;
	} 
	cin >> s;
	ans += dp();
	cout << ((ans % MOD) + MOD) % MOD;
}