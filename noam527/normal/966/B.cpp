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

int n;
ll x[2];
vector<pair<int, int>> c;
vector<int> can[2];
vector<int> ans[2];

int main() {
	fast;
	cin >> n >> x[0] >> x[1];
	c.resize(n);
	can[0].resize(n, 0);
	can[1].resize(n);
	for (int i = 0; i < n; i++) cin >> c[i].first, c[i].second = i + 1;
	sort(c.begin(), c.end());

	for (int i = 0; i < n; i++) {
		if (i + (x[0] + c[i].first - 1) / c[i].first <= n) can[0][i] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (i + (x[1] + c[i].first - 1) / c[i].first <= n) can[1][i] = 1;
	}

	int l[2] = { n - 1, n - 1 };
	while (l[0] >= 0 && can[0][l[0]] == 0) --l[0];
	while (l[1] >= 0 && can[1][l[1]] == 0) --l[1];
	int len[2];
	len[0] = (x[0] + c[l[0]].first - 1) / c[l[0]].first;
	len[1] = (x[1] + c[l[1]].first - 1) / c[l[1]].first;

	int nxt;
	for (int i = 0; i < n; i++) {
		nxt = i + (x[0] + c[i].first - 1) / c[i].first;
		if (l[1] >= nxt) {
			cout << "Yes" << endl;
			cout << nxt - i << " " << len[1] << endl;
			for (int j = i; j < nxt; j++) cout << c[j].second << " "; cout << endl;
			for (int j = l[1]; j < l[1] + len[1]; j++) cout << c[j].second << " "; cout << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		nxt = i + (x[1] + c[i].first - 1) / c[i].first;
		if (l[0] >= nxt) {
			cout << "Yes" << endl;
			cout << len[0] << " " << nxt - i << endl;
			for (int j = l[0]; j < l[0] + len[0]; j++) cout << c[j].second << " "; cout << endl;
			for (int j = i; j < nxt; j++) cout << c[j].second << " "; cout << endl;
			return 0;
		}
	}
	finish("No");
}