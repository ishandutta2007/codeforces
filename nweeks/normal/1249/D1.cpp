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

struct Segment
{
	int l, r, id;

	bool operator<(Segment other) const
	{
		return r < other.r or (r == other.r && id < other.id);
	}
};

const int MAX=  2e5+1;

vector<Segment> seg_beg[MAX];
vector<Segment> seg_end[MAX];

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k;
	read2(n,k);
	
	set<Segment> act;

	vector<int> to_rem;

	FOR(i, 0, n)
	{
		Segment s;
		read2(s.l, s.r);
		s.id = i;
		seg_beg[s.l].pb(s);
		seg_end[s.r+1].pb(s);
	}
	
	FOR(x,0, MAX)
	{
		for (auto s : seg_beg[x])
			act.insert(s);
		for (auto s : seg_end[x])
			act.erase(s);
		while (act.size() > k)
		{
			Segment s =*act.rbegin();
			act.erase(s);
			to_rem.pb(s.id+1);
		}
	}

	cout << to_rem.size() << endl;
	for (auto s : to_rem)
		cout << s << ' ';
	cout << endl;
}