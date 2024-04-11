#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 200007;
int tr[3][N], a[N], n;
set<int> st[3];
map<char, int> mp = {{'R', 0}, {'P', 1}, {'S', 2}};

void add(int t, int v, int d) {
	for (int i = v; i < N; i |= (i + 1))
		tr[t][i] += d;
}
int sum(int t, int v) {
	int ans = 0;
	for (int i = v; i > 0; i &= (i - 1))
		ans += tr[t][i - 1];
	return ans;
}
int sum(int t, int l, int r) {
	if (l > r)
		return 0;
	return sum(t, r + 1) - sum(t, l);
}
int qq() {
	int ans = 0;
	rep(i, 3) {
		int di = (i + 2) % 3, ui = (i + 1) % 3;
		if (st[ui].empty()) {
			ans += st[i].size();
			continue;
		}
		if (st[di].empty()) {
			continue;
		}
		ans += sum(i, *st[di].begin(), *--st[di].end());
		ans += sum(i, 0, min(*st[di].begin(), *st[ui].begin()));
		ans += sum(i, max(*--st[di].end(), *--st[ui].end()), n - 1);
	}
	return ans;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q, pos, t;
	char ch;
	string s;
	cin >> n >> q >> s;
	rep(i, n) {
		a[i] = mp[s[i]];
		add(a[i], i, 1);
		st[a[i]].insert(i);
	}
	cout << qq() << '\n';
	rep(i, q) {
		cin >> pos >> ch;
		pos--;
		st[a[pos]].erase(pos);
		add(a[pos], pos, -1);
		a[pos] = mp[ch];
		st[a[pos]].insert(pos);
		add(a[pos], pos, 1);
		cout << qq() << '\n';
	}

}