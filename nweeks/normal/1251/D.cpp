#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define FORR(v, c) for (auto &v : c)
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define dbg(x) cerr<<#x<<" = " << (x) << endl
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x, y, z) cin >> x >> y >> z
#define read4(a, b, c, d) cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

struct Arrete { int v, c;};
struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

typedef	vector<int>	vi;
typedef pair<int,int>	ii;
typedef vector<string>	vs;
typedef vector<ii>	vii;
typedef vector<Arrete>	vg;
typedef vector<long long>	vl;
typedef	long long ll;

struct Inter
{
	ll l, r;

	bool operator<(Inter other) const
	{
		return l < other.l or (l == other.l && r < other.r);
	}
};

ll solve(void)
{
	ll n, s;
	read2(n, s);

	vector<Inter> inter(n);
	FOR(i,0,n)
		read2(inter[i].l, inter[i].r);

	sort(rall(inter));

	FOR(i,0, n)
		s -= inter[i].l;

	ll need = (n+1)/2;
	ll lo = inter[need-1].l;
	ll up = lo+s;

	while (lo < up)
	{
		ll med = (lo+up+1)/2;

		ll mon_left(s);
		ll left(need);
		FOR(i,0, n)
			if (inter[i].r >= med && left > 0)
				left--, mon_left -= max(0LL, med - inter[i].l);
		if (left > 0 or mon_left < 0)
			up = med-1;
		else
			lo = med;
	}
	return lo;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int q;
	read(q);
	while (q--)
		pnl(solve());
}