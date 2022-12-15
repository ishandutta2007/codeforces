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

const int MAXN = 1e6+1;
ll dp[4][MAXN];
/*
	0 : ""
	1: "w"
	2: "ow"
	3: "wow"
*/


int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	string s;
	read(s);
	vi sel;
	int n = s.size();
	int l(0), r(n-1);

	while (l +1< r-1)
	{
		if (s[l] == s[r])
		{
			sel.pb(l);
			sel.pb(r);
			l++;
			r--;
		}
		else if (s[l] == s[r-1])
		{
			sel.pb(l);
			sel.pb(r-1);
			l++;
			r-=2;
		}
		else if (s[l+1] == s[r])
		{
			sel.pb(l+1);
			sel.pb(r);
			l+=2;
			r--;
		}
		else 
		{
			sel.pb(l+1);
			sel.pb(r-1);
			l+=2;
			r -=2;
		}
	}
	if (l <= r)
		sel.pb(l);
	sort(all(sel));
	for (auto v : sel) cout << s[v];
	cout << endl;
}