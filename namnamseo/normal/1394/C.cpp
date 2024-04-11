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

const int maxn = int(3e5) + 10;

int n;
pp p[maxn];

pp in() {
	static char s[500010];
	cin >> s;
	int cnt[2] = {0, 0};
	for(int i=0; s[i]; ++i)
		++cnt[s[i]=='N'];
	return {cnt[0], cnt[1]};
}

int main()
{
	cppio();
	cin >> n;
	rrep(i, n) p[i] = in();

	pp ans;

	auto test = [&](ll d) {
		ll minx = 0, miny = 0;
		ll maxx = 1e9, maxy = 1e9;
		ll mind = -1e9, maxd = 1e9;
		rrep(i, n) {
			ll x, y; tie(x, y) = p[i];
			minx = max(minx, x-d);
			miny = max(miny, y-d);

			maxx = min(maxx, x+d);
			maxy = min(maxy, y+d);

			ll df = y-x;
			mind = max(mind, df-d);
			maxd = min(maxd, df+d);
		}

		ll dl = max(mind, miny-maxx);
		ll dr = min(maxd, maxy-minx);

		if (dl <= dr) {
			for(const pp p : {pp{maxx, dl+maxx}, pp{maxy-dl, maxy}}) {
				if (minx <= p.x && p.x <= maxx &&
					miny <= p.y && p.y <= maxy &&
					mind <= p.y-p.x &&
					maxd >= p.y-p.x &&
					(p.x || p.y)) {
					ans = p;
					return 1;
				}
			}
		}
		return 0;
	};

	ll l = -1, r = 5e8;
	while (l+1 < r) {
		ll mid = (l+r)/2;

		if (test(mid)) r=mid;
		else l=mid;
	}

	cout << r << '\n';
	test(r);
	int x, y; tie(x, y) = ans;
	for(;x--;) cout << 'B';
	for(;y--;) cout << 'N';
	cout << '\n';
	return 0;
}