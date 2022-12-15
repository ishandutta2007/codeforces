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

const int MAXN = 2e5;

int dx[MAXN];
int dy[MAXN];
int n;
int x, y;
string s;

bool can(int len)
{
	for (int i(0); i + len-1 < n; ++i)
	{
		int leftx = (i ? dx[i-1] : 0) - dx[i+len-1] + dx[n-1];
		int lefty = (i ? dy[i-1] : 0) - dy[i+len-1] + dy[n-1];
		if (len >= abs(leftx-x)+abs(lefty-y) and (len -leftx+x-lefty+y)%2==0)
			return true;
	}
	return false;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	read(n);
	read(s);
	
	FOR(i,0,n)
	{
		if (s[i] == 'U')
			dy[i] = 1;
		if (s[i] == 'D')
			dy[i] = -1;
		if (s[i] == 'L')
			dx[i] = -1;
		if (s[i] == 'R')
			dx[i] = 1;
	}

	FOR(i,0,n-1)
		dy[i+1] += dy[i], dx[i+1] += dx[i];

	read2(x, y);
	
	if (x == dx[n-1] and y == dy[n-1])
	{
		cout << 0 << endl;
		return 0;
	}
	int l(1), r(n);
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (can(mid))
			r = mid;
		else
			l = mid+1;
	}
	if (!can(l))
		cout << -1 << endl;
	else
		cout << l << endl;

}