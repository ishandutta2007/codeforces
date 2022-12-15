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

struct Seat_empty
{
	int id, w;

	bool operator<(Seat_empty other) const
	{
		return w > other.w;
	}
};

struct Seat_taken
{
	int id, w;

	bool operator<(Seat_taken other) const
	{
		return w < other.w;
	}
};

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	priority_queue<Seat_empty> empty;
	priority_queue<Seat_taken> taken;
	FOR(i,0,n)
	{
		int w;
		cin >> w;
		empty.push({i+1, w});
	}

	string s;
	read(s);
	for (auto c : s)
	{
		if (c == '0')
		{
			cout << empty.top().id << ' ';
			taken.push({empty.top().id, empty.top().w});
			empty.pop();
		}
		else
		{
			cout << taken.top().id << ' ';
			taken.pop();
		}
	}
	cout << endl;
}