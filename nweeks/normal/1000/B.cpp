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

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};


int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n, M;
	read2(n, M);
	vl a(n);
	readv(a);
	a.pb(M);
	n++;
	vl on(n+1);
	vl off(n+1);

	ll total_time(0);

	int prev(0);
	bool state = true;
	FOR(i,0, n)
	{
		if (state)
		{
			total_time += a[i] - prev;
			on[i] += a[i] - prev;
		}
		else if (i)
			off[i] += a[i] - prev;
		state ^= 1;
		prev = a[i];
	}
	for (int i(n-1); i >=0; --i)
		on[i] += on[i+1], off[i] += off[i+1];

	ll ans(total_time);

	state = true;
	prev = 0;
	ll cur(0);
	FOR(i,0,n)
	{
		if (state)
			cur += a[i] - prev;
		if ((i == 0 and a[i] != 1) or (i != 0 and a[i] - a[i-1] > 1))
		{
			ll t=cur; 
			if (state)
				t--;
			else
				t++;
			if (i != n-1)
				t += off[i+1];
			ans = max(t, ans);
		}
		prev = a[i];
		state ^= 1;

		if (i != n-1 and a[i+1] - a[i] > 1)
		{
			if (state)
			{
				ll t = cur + 1 + off[i+2];
				ans = max(t, ans);
			}
			else
			{
				ll t = cur + a[i+1] - prev - 1 + off[i+2];
				ans = max(t, ans);
			}
		}
	}
	pnl(ans);

}