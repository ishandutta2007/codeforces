#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

const int N = 2005;

const string val[10] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };

int calc(const string &from, const string &to) {
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
		if (from[i] == '1' && to[i] == '0') return -1;
		cnt += to[i] - from[i];
	}
	return cnt;
}

int dp[N][N];

int n, k;
vector<string> a;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	a.resize(n);
	for (auto &i : a) cin >> i;
	for (int v = 0; v < 10; v++) {
		int x = calc(a[n - 1], val[v]);
		if (x != -1 && x <= k)
			dp[n - 1][x] = 1;
	}
	dp[n][0] = 1;
	for (int i = n - 2; i >= 0; i--) {
		for (int v = 0; v < 10; v++) {
			int x = calc(a[i], val[v]);
			if (x != -1) {
				for (int s = x; s <= k; s++)
					if (dp[i + 1][s - x])
						dp[i][s] = 1;
			}
		}
	}

	if (!dp[0][k]) {
		cout << "-1\n";
		return 0;
	}
	int cnt = k;
	for (int i = 0; i < n; i++) {
		for (int v = 9; v >= 0; v--) {
			int x = calc(a[i], val[v]);
			if (x != -1 && x <= cnt && dp[i + 1][cnt - x]) {
				cnt -= x;
				cout << v;
				break;
			}
		}
	}
}