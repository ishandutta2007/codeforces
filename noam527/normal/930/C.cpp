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
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

vector<int> lis(const vector<int> &a) {
	int n = a.size();
	vector<int> dp(n + 1, inf);
	dp[0] = -1;
	int l = 0, lo, hi, mid;
	vector<int> rtn;
	for (const auto &i : a) {
		lo = 0, hi = l;
		while (lo < hi) {
			mid = (lo + hi + 1) / 2;
			if (dp[mid] > i) hi = mid - 1;
			else lo = mid;
		}
		l = max(l, ++lo);
		dp[lo] = i;
		rtn.push_back(lo);
	}
	return rtn;
}

int n, m;
vector<int> a;

int main() {
	fast;
	cin >> n >> m;
	a.resize(m, 0);
	for (int i = 0, u, v; i < n; i++) {
		cin >> u >> v;
		--u, v;
		a[u]++;
		if (v < m) a[v]--;
	}
	for (int i = 1; i < m; i++) a[i] += a[i - 1];

	vector<int> l1, l2;
	l1 = lis(a);
	reverse(a.begin(), a.end());
	l2 = lis(a);
	reverse(l2.begin(), l2.end());

//	for (int i = 0; i < m; i++) cout << l1[i] << " "; cout << endl;
//	for (int i = 0; i < m; i++) cout << l2[i] << " "; cout << endl;
	int mx = 0;
	for (int i = 0; i < m; i++)
		mx = max(mx, l1[i] + l2[i] - 1);
	cout << mx << endl;
}