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

const int maxn = int(1e6) + 10;
int n;
int p[maxn];
int s[maxn], sn;

bool vis[maxn];

const int mod = int(1e9) + 7;

ll ipow(ll b, ll e) {
	ll ret = 1;
	while (e) {
		if (e&1) (ret *= b) %= mod;
		(b *= b) %= mod; e /= 2;
	}
	return ret;
}

pll solve(int c1, int c2, int c3) {
	int t = min(c1, c2);
	int cost = 0;
	c1 -= t;
	c2 -= t;
	c3 += t;
	cost += t;

	if (c1) {
		t = c1 / 3;
		c3 += t;
		cost += 2 * t;
	} else {
		t = c2 / 3;
		c3 += 2*t;
		cost += 3*t;
	}

	return {c3, ll(cost)};
}

int main()
{
	cppio();

	int tc;
	cin >> tc;
rep(tci, tc) {
	int cnv = 0;

	cin >> n;
	rrep(i, n) cin >> p[i];

	fill(vis+1, vis+n+1, 0); sn = 0;
	rrep(i, n) if (!vis[i]) {
		s[sn] = 0;
		for (int j=i; !vis[j]; j=p[j]) {
			++s[sn]; vis[j] = 1;
		}
		++sn;
	}

	int cnt[10]; fill(cnt, cnt+10, 0);
	int ss = accumulate(s, s+sn, 0);

	auto naive = [&](int x) {
		cnt[3] += x/3;
		cnv += x/3 - !(x%3);
		if (x%3) cnt[x%3] += 1;
	};

	if (ss % 3 == 0) {
		rep(si, sn) naive(s[si]);
		auto [ans, cost] = solve(cnt[1], cnt[2], cnt[3]);
		ans = ipow(3, ans);
		cost += cnv;
		cout << ans << ' ' << cost << '\n';
	} else if (ss % 3 == 1) {
		// make 3... 2 2 or 3...4.
		rep(si, sn) {
			int x = s[si];
			if (x >= 4 && x % 3 == 1) {
				cnt[3] += x / 3 - 1;
				cnv += x/3 - 1;
				++cnt[4];
			} else naive(x);
		}

		// 1, 2, 4.
		ll maxc = -1, minc = 1ll<<60;
		auto relax = [&](int c1, int c2, int c3, int c4, int cadd) {
			auto [ans, cost] = solve(c1+c4, c2, c3+c4);
			cost += cadd + c4;
			if (maxc < ans) {
				maxc = ans;
				minc = cost;
			} else {
				minc = min(minc, cost);
			}
		};

		if (cnt[4] >= 1) {
			relax(cnt[1], cnt[2], cnt[3], cnt[4]-1, 0);
		}
		if (cnt[1] >= 4) {
			relax(cnt[1]-4, cnt[2], cnt[3], cnt[4], 2);
		}
		if (cnt[2] >= 2) {
			relax(cnt[1], cnt[2]-2, cnt[3], cnt[4], 0);
		}
		if (cnt[2] >= 1 && cnt[1] >= 2) {
			relax(cnt[1]-2, cnt[2]-1, cnt[3], cnt[4], 1);
		}
		if (cnt[3] >= 1 && cnt[1] >= 1) {
			relax(cnt[1]-1, cnt[2], cnt[3]-1, cnt[4], 1);
		}

		ll ans = (ipow(3, maxc) * 4) % mod;
		minc += cnv;
		cout << ans << ' ' << minc << '\n';
	} else {
		// make 3... 2.
		rep(si, sn) naive(s[si]);
		// 1, 2 left.
		bool had2 = cnt[2];
		if (had2) --cnt[2];
		else cnt[1] -= 2;

		auto [ans, cost] = solve(cnt[1], cnt[2], cnt[3]);
		ans = ipow(3, ans);

		ans = (ans * 2) % mod;
		if (!had2) ++cost;
		cost += cnv;
		cout << ans << ' ' << cost << '\n';
	}
}

	return 0;
}