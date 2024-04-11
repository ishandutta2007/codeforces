#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
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
#include <numeric>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;
//https:www.youtube.com/watch?v=LA2c-ib2wsc

using T = pii;

struct rminq {
	vector<vector<T>> a;
	vector<int> logs;
	int dep, len;
	rminq(vector<int> arr) {
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
				if (!i)a[i][j] = { arr[j], j };
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

struct rmaxq {
	vector<vector<T>> a;
	vector<int> logs;
	int dep, len;
	rmaxq(vector<int> arr) {
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
				if (!i)a[i][j] = { arr[j], j };
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

rminq* tremn;
rmaxq* tremx;

int foo(int a, int b) {
	if (a == b)return 0;
	int mni = tremn->query(a, b).ss, mxi = tremx->query(a, b).ss;
	int l = min(mni, mxi), r = max(mni, mxi);
	if (l == a && r == b)return 1;
	else return foo(a, l) + foo(l, r) + foo(r, b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
	foru(i, 0, n)cin >> a[i];
	tremn = new rminq(a);
	tremx = new rmaxq(a);
	cout << foo(0, n - 1) << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while (t--)solve();
    return 0;
}