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

const int MAXN = 1e5;

vi G[MAXN];
int n;
list<int> endings;

bool DFS(int u, int p)
{
	if (u != p and G[u].size() -1 >= 2)
		return false;
	for (auto e : G[u])
		if (e != p and !DFS(e, u))
			return false;
	if (G[u].size() == 1)
		endings.pb(u+1);
	return true;
}

void go(int start)
{
	if (!DFS(start, start))
	{
		pnl("No");
		return ;
	}
	pnl("Yes");
	cout << endings.size() << endl;
	for (auto e : endings)
		cout << start + 1 << ' ' << e <<'\n';
	cout << endl;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	read(n);
	FOR(i,0,n-1)
	{
		int u, v;
		read2(u,v);
		--u,--v;
		G[u].pb(v);
		G[v].pb(u);
	}

	for (int i(0); i < n; ++i)
	{
		if (G[i].size() == n-1)
		{
	pnl("Yes");
			cout << n-1 << endl;
			for (auto e : G[i])
				cout << e + 1 << ' ' << i+1 << '\n';
			return 0;
		}
		else if (G[i].size() > 2)
		{
			go(i);
			return 0;
		}
	}
	list<int> ans;
	pnl("Yes");
	cout << 1 << endl;
	FOR(i,0,n)
		if (G[i].size() == 1)
			ans.pb(i);
	for (auto e : ans)
		cout << e+1 << ' ';
	cout << endl;
}