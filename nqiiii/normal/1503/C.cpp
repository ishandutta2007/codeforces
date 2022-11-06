#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5;
const ll inf = 1e18;
int n;
ll f[maxn + 10], g[maxn + 10];
struct xxx {
	ll a, c;

	bool operator < (const xxx &t) const {
		return a < t.a;
	}
}a[maxn + 10];
set<pair<ll, ll> > st;

void ins(int p) {
	auto it = st.lower_bound(make_pair(g[p], 0));
	if (it != st.end() && f[p] >= it -> second) return;
	while (1) {
		auto it = st.lower_bound(make_pair(g[p], inf));
		if (it == st.begin()) break;
		--it;
		if (f[p] <= it -> second) {
			st.erase(it); continue;
		}
		if (f[p] - it -> second >= g[p] - it -> first) return;
		break;
	}
	st.insert(make_pair(g[p], f[p]));
} 

ll query(ll x) {
	auto it = st.lower_bound(make_pair(x, 0));
	ll ans = inf;
	if (it != st.end()) ans = it -> second;
	if (it != st.begin()) {
		--it;
		ans = min(ans, it -> second + x - it -> first);
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld%lld", &a[i].a, &a[i].c);
	sort(a + 1, a + n + 1);
	f[1] = 0;
	g[1] = a[1].a + a[1].c;
	ins(1);
	for (int i = 2; i <= n; ++i) {
		f[i] = query(a[i].a);
		g[i] = max(g[i - 1], a[i].a + a[i].c);
		ins(i);
	}
	ll ans = f[n];
	for (int i = 1; i <= n; ++i)
		ans += a[i].c;
	printf("%lld", ans);
}