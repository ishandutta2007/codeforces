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

const int MAXN = 2e5;
int N;
int sticks[MAXN];


bool solve(void)
{
	read(N);
	FOR(i,0,4*N)
		read(sticks[i]);
	sort(sticks, sticks + 4*N);

	int r = 4*N-1;
	int l = 0;
	int prod = sticks[l] * sticks[r];

	while (l < r)
	{
		if (sticks[l] != sticks[l+1] or sticks[r] != sticks[r-1] or sticks[l]*sticks[r] != prod)
			return false;
		l+=2;
		r-=2;
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int Q;
	read(Q);
	while (Q--)
		pnl( (solve() ? "YES" : "NO"));
}