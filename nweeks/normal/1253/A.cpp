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

struct Arete { int v, c;};
struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

typedef	vector<int>	vi;
typedef pair<int,int>	ii;
typedef vector<string>	vs;
typedef vector<ii>	vii;
typedef vector<Arete>	vg;
typedef vector<long long>	vl;
typedef	long long ll;

const int MAXN = 2e5;

void solve(void)
{
	int n;
	read(n);
	vi a(n);
	vi b(n);
	readv(a);
	readv(b);
	FOR(i,0,n)
		b[i] -= a[i];
	
	int i(0);
	bool found(false);
	bool cur = false;
	int val = -1;
	while (i < n)
	{
		if (b[i] <0)
		{
			cout << "NO" << endl;
			return ;
		}
		if (b[i] == 0)
		{
			if (cur)
				cur = false;
			++i;
			continue ;
		}
		if (found and !cur) 
		{
			cout << "NO" << endl;
			return;
		}
		if (found and val != b[i])
		{
			cout << "NO" << endl;
			return;
		}
		cur = true;
		found = true;
		val = b[i];
		++i;
	}
	cout << "YES" << endl;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	read(t);
	while (t--)
		solve();
}