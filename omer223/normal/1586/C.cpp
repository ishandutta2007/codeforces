#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <numeric>
#include <random>
#include <time.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
struct rminq {
	vector<vector<T>> a;
	vector<int> logs;
	int dep, len;
	rminq(vector<T> arr) {
		len = arr.size();
		dep = 0;
		int tmp = len;
		while (tmp) {
			tmp >>= 1;
			dep++;
		}
		a.resize(dep);
		foru(i, 0, dep) {
			a[i].resize(len);
			for (int j = 0; j + (1 << i) <= len; j++) {
				if (!i)a[i][j] = arr[j];
				else a[i][j] = min(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
			}
		}
		initLogs();
	}
	void initLogs() {
		logs.resize(len + 1);
		logs[1] = 0;
		foru(i, 2, len + 1)logs[i] = logs[i >> 1] + 1;
	}
	T query(int l, int r) {
		int mylen = logs[r - l + 1];
		return min(a[mylen][l], a[mylen][r - (1 << mylen) + 1]);
	}
};

template<class T>
struct rmaxq {
	vector<vector<T>> a;
	vector<int> logs;
	int dep, len;
	rmaxq(vector<T> arr) {
		len = arr.size();
		dep = 0;
		int tmp = len;
		while (tmp) {
			tmp >>= 1;
			dep++;
		}
		a.resize(dep);
		foru(i, 0, dep) {
			a[i].resize(len);
			for (int j = 0; j + (1 << i) <= len; j++) {
				if (!i)a[i][j] = arr[j];
				else a[i][j] = max(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
			}
		}
		initLogs();
	}
	void initLogs() {
		logs.resize(len + 1);
		logs[1] = 0;
		foru(i, 2, len + 1)logs[i] = logs[i >> 1] + 1;
	}
	T query(int l, int r) {
		int mylen = logs[r - l + 1];
		return max(a[mylen][l], a[mylen][r - (1 << mylen) + 1]);
	}
};

void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	foru(i, 0, n)cin >> grid[i];
	vector<vector<int>> fastup(n, vector<int>(m, -1e9)), farleft(n, vector<int>(m, 1e9));
	foru(i, 0, n) {
		foru(j, 0, m) {
			if (i == 0)fastup[i][j] = j;
			else {
				if (grid[i - 1][j] == '.')fastup[i][j] = max(fastup[i][j], fastup[i - 1][j]);
				if (j != 0&&grid[i][j-1]=='.')fastup[i][j] = max(fastup[i][j], fastup[i][j - 1]);
			}
			farleft[i][j] = j;
			if (j!=0 && grid[i][j - 1] == '.')farleft[i][j] = min(farleft[i][j], farleft[i][j - 1]);
			if (i != 0 && grid[i - 1][j] == '.')farleft[i][j] = min(farleft[i][j], farleft[i - 1][j]);
		}
	}
	vector<int> fl(m,-1e9);
	foru(j, 0, m) {
		foru(i, 0, n) {
			if (fastup[i][j] == -1e9)fl[j] = max(fl[j], farleft[i][j]);
		}
	}
	rmaxq<int> rm(fl);
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		int t = rm.query(--x, --y);
		if (t > x)cout << "NO\n";
		else cout << "YES\n";
	}
}

int main() {
	fast;
	int t;
	//cin >> t;
	t = 1;
	while (t--)solve();
	return 0;
}