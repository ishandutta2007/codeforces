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

void solve(void)
{
	ll n;
	read(n);
	ll cpy = n;

	vi decomp;
	while (n)
	{
		decomp.pb(n%3);
		n/=3;
	}

	int sz = decomp.size() - 1;
	while (sz >= 0 && decomp[sz] != 2)
		sz--;
	
	if (sz == -1)
		cout << cpy << endl;
	else
	{
		for (int k(0); k < sz; ++k)
			decomp[k] = 0;
		while (sz < decomp.size() - 1 && decomp[sz] == 2)
		{
			decomp[sz] = 0;
			decomp[++sz]++;
		}
		if (decomp[sz] == 2)
		{
			ll ans(1);
			for (int k(0); k <= sz; ++k)
				ans *= 3;
				cout << ans << endl;
		}
		else
		{
			ll ans(0);
			ll p = 1;
			for (int k(0); k < decomp.size(); ++k)
			{
				if (decomp[k])
					ans += p;
				p*=3;
			}
			cout << ans << endl;
		}
	}
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int q;
	read(q);
	while (q--)
		solve();
}