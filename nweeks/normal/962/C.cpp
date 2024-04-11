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

int ans = 1e9;

bool is_square(string s)
{
	ll n(0);
	for (auto c : s)
		n = n * 10 + c-'0';
	return sqrt(n) == (int)sqrt(n);
}

void compute(string s, int d)
{
	if (d >= ans) return ;
	if (s.size() == 0)
		return ;
	if (is_square(s))
	{
		ans = min(ans, d);
		return ;
	}
	for (int i(0); i < s.size(); ++i)
	{
		if (i == 0 and (s.size() > 1 and s[1] == '0')) continue;
		string n = "";
		for (int k(0); k < s.size(); ++k)
			if (k != i)
				n += s[k];
		compute(n, d+1);
	}
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	string s;
	read(s);
	compute(s, 0);
	cout << (ans == 1e9 ? -1 : ans) << endl;
}