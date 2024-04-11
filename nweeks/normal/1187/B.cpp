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

string shop;
string desired;
int lettershop[26][MAXN];;
int needed[26];

bool can(int r)
{
	for (int i(0); i < 26; ++i)
		if (lettershop[i][r] < needed[i])
			return false;
	return true;
}

int solveQ(void)
{
	read(desired);
	for (int i(0); i < 26; ++i) needed[i] = 0;
	for (int i(0); i < desired.size(); ++i)
		needed[desired[i] - 'a']++;
	int l = 0;
	int r = shop.size() - 1;

	while (l < r)
	{
		int mid = (l+r)/2;
		if (can(mid))
			r = mid;
		else
			l = mid+1;
	}
	return l+1;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int Q;
	read2(Q, shop);
	
	lettershop[shop[0] -'a'][0] = 1;
	
	for (int i(1); i < shop.size(); ++i)
		for (int j(0); j < 26; ++j)
			lettershop[j][i] = lettershop[j][i-1] + (shop[i] - 'a' == j);

	read(Q);
	while (Q--)
		pnl(solveQ());
}