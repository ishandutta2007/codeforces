#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, set<pair<int, int> > > mp;
map<pair<int, int>, int> ans;
int q, op, x, y, tot;
pair<int, int> mk(int x, int y) {
	return make_pair(x / __gcd(x, y), y / __gcd(x, y));
}
ll d(ll x, ll y) {
	return x * x + y * y;
}
int main() {
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			++tot;
			for (auto i: mp[d(x, y)])
				ans[mk(x + i.first, y + i.second)] += 2;
			++ans[mk(x, y)]; mp[d(x, y)].insert(make_pair(x, y));
		} else if (op == 2) {
			--tot;
			--ans[mk(x, y)]; mp[d(x, y)].erase(make_pair(x, y));
			for (auto i: mp[d(x, y)])
				ans[mk(x + i.first, y + i.second)] -= 2;
		} else printf("%d\n", tot - ans[mk(x, y)]);
	}
}