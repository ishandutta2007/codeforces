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

void solve(void)
{
	int n;
	read(n);
	int a, b, c;
	read3(a, b, c);
	
	int aa(0), bb(0), cc(0);
	string s;
	read(s);
	FOR(i,0,n)
	{
		char c = s[i];
		if (c == 'R')
			aa++;
		else if (c == 'P')
			bb++;
		else
			cc++;
	}
	
	// a : rock, b : paper c : scisors     a > c > b > a
	string print = s;
	if (2*(min(a, cc) + min(c, bb) + min(b, aa)) >= n)
	{
		cout << "YES" << endl;
		for (int i(0); i < n; ++i)
		{
			if (s[i] == 'R' and b > 0)
				b--, print[i] = 'P';
			else if (s[i] == 'R')
				print[i] = 0;
		}
		FOR(i,0,n)
		{
			if (s[i] == 'P' and c > 0)
				c--, print[i] = 'S';
			else if (s[i] == 'P')
				print[i] = 0;
		}
		FOR(i,0,n)
		{
			if (s[i] == 'S' and a > 0)
				a--, print[i] = 'R';
			else if(s[i] == 'S')
				print[i] = 0;
		}
		FOR(i,0,n)
		{
			if (print[i] == 0)
			{
				if (a > 0)
					a--, print[i] = 'R';
				else if (b > 0)
					b--, print[i] = 'P';
				else
					c--, print[i] = 'S';
			}
		}
		cout << print << endl;
	}
	else
		cout << "NO" << endl;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int q;
	read(q);
	while (q--)
		solve();
}