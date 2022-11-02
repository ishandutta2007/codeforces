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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> b(n);
	pii lr{ m - 1,m - 1 }, ud{ n - 1,n - 1 };
	foru(i, 0, n)cin >> b[i];
	foru(i, 0, n) {
		foru(j, 0, m) {
			if (b[i][j] == 'R') {
				lr.ff = min(lr.ff, j);
				lr.ss = min(lr.ss, m - j - 1);
				ud.ff = min(ud.ff, i);
				ud.ss = min(ud.ss, n - i - 1);
			}
		}
	}
	bool found = 0;
	foru(i, 0, n) {
		foru(j, 0, m) {
			if (b[i][j] == 'R') {
				int di = i, dj = j;
				if (di <= ud.ff && dj <= lr.ff)found = 1;
			}
		}
	}
	if (!found)cout << "NO\n";
	else cout << "YES\n";
}


int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}