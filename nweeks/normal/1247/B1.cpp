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

int solve(void)
{
	int n, k, d;

	read3(n, k, d);

	map<int, int> m;

	int cnt(0);
	vi a(n);
	readv(a);
	int ans = 1e9;

	for (int i(0); i < n; ++i)
	{
		m[a[i]] += 1;
		if (m[a[i]] == 1)
			cnt++;
		if (i >= d)
		{
			m[a[i-d]] -= 1;
			if (m[a[i-d]] == 0)
				cnt--;
		}
		if (i >= d-1)
			ans = min(ans, cnt);
	}
	return ans;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	read(t);
	while (t--)
		pnl(solve());
}