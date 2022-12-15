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


int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	string s;
	read(s);

	int rows(1);
	while (rows * 20 < s.size()) rows++;

	int col(1);
	while (rows * col < s.size()) col++;

	int tot = rows * col;
	int rem = tot - s.size();
	int per_row = rem/rows;
	int left = rem - per_row * rows;
	int cur(0);
	cout << rows << ' ' << col << endl;
	FOR(i,0, rows)
	{
		FOR(j,0, per_row)
			cout << '*';
		int to_print = col - per_row - (left > 0);
		if (left-- > 0) cout << '*';
		FOR(j, 0, to_print)
			cout << s[cur++];
		cout << endl;
	}
}