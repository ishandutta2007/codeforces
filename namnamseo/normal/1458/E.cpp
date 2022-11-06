#include <bits/stdc++.h>
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
#define xy(z) z.x, z.y
#define printf if(1) printf

const int maxn = int(2e5) + 10;

int n, m;
pp a[maxn];
struct qry {
	int x, y, ai;
} q[maxn];
int ans[maxn];

const int inf = 1.1e9;

int main()
{
	cppio();
	cin >> n >> m;
	rrep(i, n) cin >> a[i].x >> a[i].y;
	rrep(i, m) { cin >> q[i].x >> q[i].y; q[i].ai = i; }

	a[++n] = {0, 0};
	sort(a+1, a+n+1);
	sort(q+1, q+m+1, [&](const qry& a, const qry& b) {
		return tie(a.x, a.y) < tie(b.x, b.y);
	});
	set<pp> s;
	s.emplace(0, inf);

	int qi = 1;

	auto containing = [&](int x) {
		auto it = s.lower_bound(pp{x+1, -1});
		if (it == s.begin()) return s.end();
		--it;
		if (it->x <= x && x <= it->y) return it;
		return s.end();
	};

	auto decrem = [&](int amnt) {
		while (amnt) {
			int l, r; tie(l, r) = *s.begin();
			int t = min(r-l+1, amnt);
			amnt -= t;
			l += t;
			s.erase(s.begin());
			if (l <= r) s.emplace(l, r);
		}
	};

	for (int i=1, ni, rl=-1; i<=n; i=ni) {
		for(ni=i; ni<=n; ++ni) if (a[i].x != a[ni].x) break;

		if (rl != -1) decrem(a[i].x - 1 - rl);
		rl = a[i].x;

		bool forced = (a[i].y < s.begin()->x);
		int gy = a[i].y;

		if (!forced) {
			gy = s.begin()->x;
			decrem(1);
		}

		for (int j=i; j<ni; ++j) {
			int y = a[j].y;

			auto it = containing(y);
			if (it == s.end()) continue;

			int l, r; tie(l, r) = *it;
			s.erase(it);
			if (l <= y-1) s.emplace(l, y-1);
			if (y+1 <= r) s.emplace(y+1, r);
		}

		int nr = (ni > n ? inf : a[ni].x);
		for(; qi<=m; ++qi) {
			if (q[qi].x >= nr) break;
			int &av = ans[q[qi].ai];

			if (q[qi].x == a[i].x) {
				if (forced) {
					av = 1;
				} else {
					av = (q[qi].y != gy);
				}
				continue;
			}

			if (rl+1 < q[qi].x) {
				decrem(q[qi].x - (rl+1));
				rl = q[qi].x - 1;
			}

			av = (q[qi].y != s.begin()->x);
		}
	}

	rrep(i, m) {
		pp tmp{q[i].x, q[i].y};
		int idx = lower_bound(a+1, a+n+1, tmp) - a;
		if (idx <= n && a[idx] == tmp) ans[q[i].ai] = 0;
	}

	rrep(i, m) {
		cout << ((ans[i] ? "WIN" : "LOSE")) << '\n';
	}

	return 0;
}