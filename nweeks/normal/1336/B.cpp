#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(i, j, n) for (int i(j); i < (n); ++i)
#define FORR(v, c) for (auto &v : (c))
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x, y, z) cin >> x >> y >> z
#define read4(a, b, c, d) cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

typedef	vector<int>	vi;
typedef vector<long long>	vl;
typedef	long long ll;

ll get(vector<ll> a, vector<ll> b, vector<ll> c)
{
	ll ans(2.5e18);
	FORR(v, a)
	{
		if (v<b[0]) continue;
		if (v > c.back()) continue;
		int lo(0), up(SZ(b)-1);
		while (lo<up)
		{
			int mid = (lo+up+1)/2;
			if (b[mid]<=v)
				lo=mid;
			else
				up=mid-1;
		}
		int lolo(0), upup(SZ(c)-1);
		while (lolo<upup)
		{
			int mid = (lolo+upup)/2;
			if (c[mid] >= v)
				upup=mid;
			else
				lolo=mid+1;
		}
		ans = min(ans, SQ(v-b[lo])+SQ(v-c[lolo])+SQ(b[lo]-c[lolo]));
	}
	return ans;
}

void solve(void)
{
	int nr, nb, ng;
	read3(nr,nb,ng);
	vector<ll> r(nr), b(nb), g(ng);
	readv(r);
	readv(b);
	readv(g);
	sort(all(r));
	sort(all(b));
	sort(all(g));
	ll ans = min({get(r,b,g), get(r,g,b), get(b,r,g), get(b,g,r),
								get(g, r, b), get(g, b, r)});
	pnl(ans);
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int __t(1);
	cin >> __t;
	while (__t--)
		solve();
}