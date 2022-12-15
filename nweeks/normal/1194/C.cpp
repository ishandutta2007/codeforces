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

bool solveQ(void)
{
	string s,t,p;
	read3(s,t,p);

	int n(s.size()), m(t.size()), l(p.size());

	vi lettershop(26,0);
	for (int i(0); i < l; ++i)
		lettershop[p[i] - 'a']++;
	
	int i=0;
	int j=0;
	while (i < n && j < m)
	{
		if (s[i] == t[j])
			++i, ++j;
		else
			lettershop[t[j++]-'a']--;
	}
	if (i < n) return false;
	while (j < m)
		lettershop[t[j++] - 'a']--;
	for (int i(0); i < 26; ++i)
		if (lettershop[i] < 0)
			return false;
	return true;
	
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int Q;
	read(Q);
	while (Q--)
	{
		if (solveQ()) pnl("YES");
		else		pnl("NO");
	}
}