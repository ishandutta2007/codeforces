#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int N = 260, M = 100002;
int dp[N][N][N], nc[26][M], sl;
vector<string> a(3);


void rel(int p1, int p2, int p3) {
	dp[p1][p2][p3] = sl + 1;
	if (p1 > 0)
		dp[p1][p2][p3] = min(dp[p1][p2][p3], nc[a[0][p1 - 1] - 'a'][dp[p1 - 1][p2][p3]] + 1);
	if (p2 > 0)
		dp[p1][p2][p3] = min(dp[p1][p2][p3], nc[a[1][p2 - 1] - 'a'][dp[p1][p2 - 1][p3]] + 1);
	if (p3 > 0)
		dp[p1][p2][p3] = min(dp[p1][p2][p3], nc[a[2][p3 - 1] - 'a'][dp[p1][p2][p3 - 1]] + 1);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;	
	string s;
	cin >> n >> q >> s;
	sl = s.size();
	rep(i, 26)
		nc[i][sl] = nc[i][sl + 1] = sl + 1;
	for (int i = sl - 1; i >= 0; i--) {
		rep(j, 26)
			nc[j][i] = (s[i] == 'a' + j ? i : nc[j][i + 1]);
	}
	int t;
	char cc, c;
	rep(i, q) {
		cin >> cc >> t;
		t--;
		if (cc == '-')
			a[t].pop_back();
		else {
			cin >> c;
			a[t].push_back(c);
			for (int p1 = (t == 0 ? a[0].size() : 0); p1 <= a[0].size(); p1++)
				for (int p2 = (t == 1 ? a[1].size() : 0); p2 <= a[1].size(); p2++)
					for (int p3 = (t == 2 ? a[2].size() : 0); p3 <= a[2].size(); p3++)
						rel(p1, p2, p3);
		}
		if (dp[a[0].size()][a[1].size()][a[2].size()] <= sl)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}