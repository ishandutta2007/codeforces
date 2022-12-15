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

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	read(s);
	set<char> letters;
	for (auto c : s) letters.insert(c);

	if (letters.size() <= 1 or letters.size() > 4)
	{
		cout << "No" << endl;
		return 0;
	}

	if (letters.size() == 2)
	{
		for (auto c : letters)
		{
			int cnt(0);
			for (auto k : s)
				cnt += k == c;
			if (cnt == 1)
			{
				cout << "No" << endl;
				return 0;
			}	
		}
		cout << "Yes" << endl;
		return 0;
	}

	if (letters.size() == 3)
	{
		int occ[3] = {};
		int cur(0);
		for (auto c : letters)
		{
			for (auto k : s)
				occ[cur] += k == c;
			++cur;
		}

		if ((occ[0] == 1 and occ[1] == 1 and occ[2] == 1))
			cout << "No" << endl;
		else
			pnl("Yes");
		return 0;
	}

	pnl("Yes");
}