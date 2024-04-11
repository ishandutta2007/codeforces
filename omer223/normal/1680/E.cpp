#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <unordered_map>
#include <chrono>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;


int n;
string b[2];

int tn(int row, int col) {
	return row * n + col;
}

vector<vector<int>> foo() {
	vector<int> dpl[2];
	foru(i, 0, 2)dpl[i] = vector<int>(n + 1, 1e9);
	dpl[0][0] = 0, dpl[1][0] = 0;
	bool seen = 0;
	for (int j = 1; j <= n; j++) {
		vector<ll> prv(2);
		prv[0] = dpl[0][ j - 1], prv[1] = dpl[1][ j - 1];//TODO CHANGE
		if (b[0][j - 1] == '.' && b[1][j - 1] == '.') {
			dpl[0][j] = min(prv[1] + 2 * seen, prv[0] + seen);
			dpl[1][j] = min(prv[0] + 2 * seen, prv[1] + seen);
		}
		else if (b[0][j - 1] == '*' && b[1][j - 1] == '*') {
			dpl[0][j] = min(prv[0] + seen + 1, prv[1] + seen + 1);
			dpl[1][j] = min(prv[0] + seen + 1, prv[1] + seen + 1);
		}
		else {
			if (b[0][j - 1] == '*') {
				dpl[0][j] = min(prv[0] + seen, prv[1] + 2 * seen);
				dpl[1][j] = min(prv[0] + seen + 1, prv[1] + seen + 1);
			}
			else {
				dpl[1][j] = min(prv[1] + seen, prv[0] + 2 * seen);
				dpl[0][j] = min(prv[1] + seen + 1, prv[0] + seen + 1);
			}
		}
		if (b[0][j - 1] == '*' || b[1][j - 1] == '*')seen = 1;
	}
	vector<vector<int>> v{ dpl[0],dpl[1] };
	return v;
}

void solve() {
	cin >> n >> b[0] >> b[1];
	vector<vector<int>> dp1 = foo();
	reverse(b[0].begin(), b[0].end());
	reverse(b[1].begin(), b[1].end());
	vector<vector<int>> dp2 = foo();
	reverse(b[0].begin(), b[0].end());
	reverse(b[1].begin(), b[1].end());
	for (vector<int>& v : dp1) {
		reverse(v.begin(), v.end());
		v.pop_back();
		reverse(v.begin(), v.end());
	}
	for (vector<int>& v : dp2) {
		reverse(v.begin(), v.end());
		v.pop_back();
	}
	vector<bool> seen1(n, false), seen2(n, false);
	foru(i, 0, n) {
		seen1[i] = (i ? seen1[i - 1] : 0);
		if (b[0][i] == '*' || b[1][i] == '*')seen1[i] = 1;
	}
	ford(i, n - 1, 0) {
		seen2[i] = (i != n - 1 ? seen2[i + 1] : 0);
		if (b[0][i] == '*' || b[1][i] == '*')seen2[i] = 1;
	}
	int bst = 1e9;
	for (int j = 0; j < n; j++) {
		vector<int> l{ 0,0 }, r{ 0,0 };
		vector<bool> seen{ 0,0 };
		if (j != 0) {
			foru(i, 0, 2)l[i] = dp1[i][j - 1];
			seen[0] = seen1[j - 1];
		}
		if (j != n - 1) {
			foru(i, 0, 2)r[i] = dp2[i][j + 1];
			seen[1] = seen2[j + 1];
		}
		for (int x = 0; x < 2; x++) {
			for (int y = 0; y < 2; y++) {
				int tot = l[x] + r[y] + seen[0] + seen[1];
				bitset<2> come;
				come[0] = (x == 0 && seen[0]) || (y == 0 && seen[1]) || (b[0][j] == '*');
				come[1] = (x == 1 && seen[0]) || (y == 1 && seen[1]) || (b[1][j] == '*');
				if (come.count() == 2)tot++;
				bst = min(bst, tot);
			}
		}
	}
	cout << bst << '\n';
}


int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}