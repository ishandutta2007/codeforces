#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 100005;
int n, ls[mxN], rs[mxN];
vector<int> p;
string s;

int find_first(int l, int r) {
	for (int i = l; i <= r; ++i) {
		assert(s[i] != 'P');
		if (s[i] == '*') return i;
	}
	return r + 1;
}

int find_last(int l, int r) {
	for (int i = r; i >= l; --i) {
		assert(s[i] != 'P');
		if (s[i] == '*') return i;
	}
	return l - 1;
}

bool ok(int x) {
	int cur = -1;
	for (int i = 0; i < p.size(); ++i) {
		int l = find_first(cur + 1, p[i] - 1);
		assert(l <= p[i]);
		if (p[i] - l > x) return 0;
		cur = p[i] + max({0, x - 2 * (p[i] - l), (x - (p[i] - l)) / 2});
		cur = min(cur, i == p.size() - 1 ? n - 1 : p[i + 1]);
	}
	return cur >= find_last(p.back() + 1, n - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; ++i) if (s[i] == 'P') p.push_back(i);
	int l = 1, r = 2 * n;
	while(l < r) {
		int mid = (l + r) / 2;
		if (ok(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l;
	return 0;
}