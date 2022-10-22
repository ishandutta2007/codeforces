#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
#define pct(x) __builtin_popcount(x)
#define large(x) 31 - __builtin_clz(x)

const unsigned long long SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
 
const int mxN = 2048;
int n, ans[mxN], arr[mxN];
int numQry = 0;
 
int qry(int a, int b) {
	assert(0 <= a && a < n && 0 <= b && b < n && a != b);
	assert(++numQry <= 4269);
	cout << "? " << a + 1 << " " << b + 1 << endl;
	int x; cin >> x;
	if (x == -1) exit(0);
	return x;
}

int find(vector<int> v) {
	//debug(v);
	assert(!v.empty());
	if (v.size() == 1) return v[0];
	map<int, vector<int>> mp;
	for (int i = 1; i < v.size(); ++i) {
		mp[qry(v[0], v[i])].push_back(v[i]);
	}
	//check if its already 0
	if (mp.size() == v.size() - 1 && pct(mp.rbegin()->first) <= large((int)v.size())) {
		return v[0];
	}
	return find(mp.begin()->second);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int goodStart = -1;
	while(goodStart == -1) {
		int cand = rng() % n;
		bool good = 0;
		set<int> checked = {cand};
		while(checked.size() < n && checked.size() <= 10) {
			int other = rng() % n;
			if (checked.find(other) != checked.end()) continue;
			int x = qry(cand, other);
			if (pct(x) < 10 && (x & (n - 1)) < n - 1) {
				good = 1;
				break;
			}
			checked.insert(other);
		}
		if (good) {
			goodStart = cand;
			break;
		}
	}
	//debug(goodStart);
	assert(0 <= goodStart && goodStart < n);
	vector<int> v = {goodStart};
	for (int i = 0; i < n; ++i) {
		if (i != goodStart) {
			v.push_back(i);
		}
	}
	int zero = find(v);
	//cout << zero;
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		if (i != zero) {
			ans[i] = qry(i, zero);
		}
	}
	cout << "!";
	for (int i : ans) {
		cout << " " << i;
	}
	cout << endl;
	return 0;
}