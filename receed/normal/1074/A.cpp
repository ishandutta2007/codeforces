#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, a, b, c;
	cin >> n >> m;
	vector<int> v(n), h;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 1)
			h.push_back(b);
	}
	sort(v.begin(), v.end());
	sort(h.begin(), h.end());
	int pos = 0, ans = h.size();
	for (int i = 0; i < v.size(); i++) {
		while (pos < h.size() && h[pos] < v[i])
			pos++;
		ans = min(ans, i + (int) h.size() - pos);
	}
	int inf = 1000000000;
	while (pos < h.size() && h[pos] < inf)
		pos++;
	ans = min(ans, (int) v.size() + (int) h.size() - pos);
	cout << ans;
}