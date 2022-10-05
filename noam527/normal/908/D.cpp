#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int pw(ll b, int e) {
	int rtn = 1;
	while (e) {
		if (e & 1) rtn = rtn * b % md;
		e /= 2, b = b * b % md;
	}
	return rtn;
}
int inv(int x) {
	return pw(x, md - 2);
}

int k, p1, p2;
int p3, p4;
int dp[1001][1001];

int cal(int x, int p) {
	ll over = x + p - k;

	int ans = k;
	ans = (ans + over + (ll)p3 * inv(p4)) % md;
	return ans;
}

int calc(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];
	if (i + j >= k) return dp[i][j] = cal(i, j);
	dp[i][j] = ((ll)p3 * calc(i + 1, j) + (ll)p4 * calc(i, j + i)) % md;
	return dp[i][j];
}

int main() {
	fast;
//	cout << (500000004LL * 500000004) % md << endl;
	for (int i = 0; i < 1001; i++) for (int j = 0; j < 1001; j++) dp[i][j] = -1;
	cin >> k >> p1 >> p2;
	p3 = (ll)p1 * inv(p1 + p2) % md, p4 = (ll)p2 * inv(p1 + p2) % md;

	cout << calc(1, 0) << endl;
}