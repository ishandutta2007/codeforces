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

bool can[4][100];
int n, k;

void print(void)
{
	FOR(i,0,4)
	{
		FOR(j,0,n)
			cout << (can[i][j] ? '.' : '#');
		cout<<endl;
	}
}

int		main(int ac, char **av)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	read2(n, k);
	pnl("YES");
	FOR(i,0,4) FOR(j,0,n) can[i][j] = true;
	
	if (k == 2 * (n-2))
	{
		FOR(i,1,3) FOR(j,1,n-1) can[i][j] = false;
		print();
		return 0;
	}

	if  (k & 1)
		can[1][n/2] = false, k--;
	
	for (int i(1); n/2 - i > 0 and k > 0; ++i, k -= 2)
		can[1][n/2-i] = can[1][n/2+i] = false;
	for (int i(1); n/2 - i > 0 and k > 0; ++i, k -= 2)
		can[2][n/2-i] = can[2][n/2+i] = false;
	print();	
}