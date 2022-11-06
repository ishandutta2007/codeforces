#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()
#define xy(A) A.x, A.y

using namespace __gnu_pbds;
typedef tree<
pp,
null_type,
less<pp>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int maxn = int(1e5) + 10;
const ll inf = 1ll<<60;

int n;
int nm;

ordered_set adjs[maxn];
ordered_set alls;
pp ev[maxn*2];
ll ew[maxn*2];

map<pp,int> rei;

bool ok(int a, int b, int c, int d) {
	return a != b && a != c && a != d &&
		b != c && b != d && c != d;
}
bool ok(int ia, int ib) {
	return ok(ev[ia].x, ev[ia].y, ev[ib].x, ev[ib].y);
}

void add_edge(int a, int b, int w) {
	if (a > b) swap(a, b);
	int ei = ++nm;
	adjs[a].insert(pp{w, ei});
	adjs[b].insert(pp{w, ei});
	alls.insert(pp{w, ei});
	ev[ei] = {a, b};
	ew[ei] = w;
	rei[pp{a, b}] = ei;
}

void del_edge(int ei) {
	int a, b; tie(a, b) = ev[ei];
	int w = ew[ei];
	adjs[a].erase(pp{w, ei});
	adjs[b].erase(pp{w, ei});
	alls.erase(pp{w, ei});
}

void What() {
	int mei = alls.begin()->second;
	int a, b; tie(a, b) = ev[mei];
	ll ans = inf;

	// first threes
	{ auto ia = adjs[a].begin();
	rep(i, 3) {
		if (ia == adjs[a].end()) break;
		auto ib = adjs[b].begin();
		rep(j, 3) {
			if (ib == adjs[b].end()) break;

			int eia = ia->second, eib = ib->second;
			if (ok(eia, eib)) {
				ans = min(ans, ew[eia] + ew[eib]);
			}

			++ib;
		}
		++ia;
	} }

	// bangpaje
	{
	auto F = [&](int v) {
		auto &s = adjs[v];
		if (s.size() < 3u) return;
		ll tmp = 0;
		auto it = s.begin();
		rep(i, 3) {
			tmp += ew[it->second];
			++it;
		}
		ans = min(ans, tmp);
	};
	F(a); F(b);
	}

	// min and other min
	{ int l = ew[mei]-1, r = int(1e9) + 10;
	while (l+1 < r) {
		int md = l + (r-l)/2;
		int cnt = (
			int(adjs[a].order_of_key(pp{md+1, -1}))+
			int(adjs[b].order_of_key(pp{md+1, -1}))-
			1
		);
		int actual = alls.order_of_key(pp{md+1, -1});

		if (cnt == actual) l = md;
		else r = md;
	}
	if (r != int(1e9) + 10) {
	ans = min(ans, r + ew[mei]); } }

	cout << ans << '\n';
}

int main()
{
	cppio();

	int m;
	cin >> n >> m;
	for (int i=1; i<=m; ++i) {
		int a, b, w; cin >> a >> b >> w;
		add_edge(a, b, w);
	}

	What();
	int q; cin >> q;
for(;q--;) {
	int cmd; cin >> cmd;
	if (cmd == 0) {
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		int ei = rei[pp{a, b}];
		del_edge(ei);
	} else {
		int a, b, c; cin >> a >> b >> c;
		add_edge(a, b, c);
	}
	What();
}

	return 0;
}