#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <memory.h>
#include <iomanip>
#include <set>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

#define rep(i, s, t) for (auto i = (s); i < (t); ++(i))
#define per(i, s, t) for (auto i = (s); i >= (t); --(i))
#define sz(x) ((int) x.size())
#define all(x) (x).begin(), (x).end()

void run();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	run();
#ifdef _DEBUG
	cerr << "OK" << endl;
	while (1);
#endif
	return 0;
}

const int N = (int) 3e5 + 123;

int n, k;
int a[N], dp[N], p[N];

bool check(int d) {
	memset(dp, 0, sizeof dp);
	memset(p, 0, sizeof p);
	dp[0] = 1;
	p[0] = 1;
	int ptr = 1;
	rep(i, 1, n + 1) {
		while (a[i] - a[ptr] > d) {
			ptr++;
		}
		int l = ptr - 1;
		int r = i - k;
		if (l <= r) {
			int cnt = p[r] - (l == 0 ? 0 : p[l - 1]);
			dp[i] = cnt > 0;
		}
		p[i] = p[i - 1] + dp[i];
	}
	return dp[n];
}

void run() {
	cin >> n >> k;
	rep(i, 1, n + 1) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int left = -1;
	int right = INF;
	while (right - left > 1) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			right = mid;
		}
		else {
			left = mid;
		}
	}
	cout << right << "\n";
}