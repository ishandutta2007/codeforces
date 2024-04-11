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

int n, nn;
vector<int> ans;

void add(vector<int> &a, int v) {
	if (v < nn) a.push_back(v);
}
void ask(vector<int> &a) {
	cout << a.size() << endl;
	for (auto &i : a) cout << i + 1 << " "; cout << endl;
	flush;
	vector<int> rtn(nn);
	for (auto &i : rtn) cin >> i;
	for (int i = 0, p = 0; i < nn; i++) {
		if (p < a.size() && i == a[p]) p++;
		else ans[i] = min(ans[i], rtn[i]);
	}
}

int main() {
	fast;
	cin >> nn;
	ans.resize(nn, 1e9 + 5);
	n = nn;
	while (n != (n & (-n))) n += (n & (-n));

	vector<int> q[2];
	for (int m = n; m > 1; m >>= 1) {
		for (int i = 0; i < n; i++)
			add(q[(i % m) / (m / 2)], i);
		ask(q[0]), ask(q[1]);
		q[0].clear(), q[1].clear();
	}
	cout << -1 << endl;
	for (auto &i : ans) cout << i << " "; cout << endl;
}