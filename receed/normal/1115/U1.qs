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
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int N = 500002;
int a[N], b[N], c[N], cc[N];
int cnt;

void add(int d, int t) {
	cc[d] += t;
	if (t > 0 && cc[d] == c[d])
		cnt++;
	if (t < 0 && cc[d] == c[d] - 1)
		cnt--;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m, k, n, s, nb = 0;
	cin >> m >> k >> n >> s;
	rep(i, m)
		cin >> a[i];
	rep(i, s) {
		cin >> b[i];
		if (!c[b[i]])
			nb++;
		c[b[i]]++;
	}
	int pos = 0, al = -1, ar = -1;
	rep(i, m) {
		while (pos < m && (pos - i < k || cnt < nb)) {
			add(a[pos], 1);
			pos++;
		}
		if (cnt == nb && pos - i >= k && i / k + (m - pos) / k + 1 >= n) {
			al = i;
			ar = pos;
			break;
		}
		if (pos == n)
			break;
		add(a[i], -1);
	}
	if (al == -1) {
		cout << -1;
		return 0;
	}
	int dd = 0;
	vector<int> ans;
	for (int i = al; i < ar; i++) {
		if (c[a[i]]) {
			c[a[i]]--;
			dd++;
		}
		else if (ar - i + dd == k)
			dd++;
		else
			ans.push_back(i);
	}
	rep(i, al % k)
		ans.push_back(i);
	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i + 1 << ' ';
}