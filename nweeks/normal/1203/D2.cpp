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

int from_l[MAXN], from_r[MAXN];

string s, t;
int N, M;

bool can(int sz)
{
	for (int i(0); i+sz-1 < N; ++i)
		if (from_l[i] > from_r[i+sz-1])
			return true;
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	read2(s, t);
	N = s.size();
	M = t.size();

	int i(0), j(0);

	while (i < N)
	{
		from_l[i] = j;
		if (j < M && s[i] == t[j])
			++j;
		++i;
	}
	
	i = N-1;
	j = M-1;
	while (i >= 0)
	{
		from_r[i] = j;
		if (j >= 0 && s[i] == t[j])
			--j;
		--i;
	}

	ll l(0), r(N-1);
	while (l < r)
	{
		ll mid = (l+r+1)/2;
		if (can(mid))
			l = mid;
		else
			r = mid-1;
	}
	pnl(l);
}