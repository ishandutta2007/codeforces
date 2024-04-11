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

const int MAX = 2e5+1;

ll solve(void)
{
	ll nb_voteurs;
	cin >> nb_voteurs;

	vector<vector<int> > voteurs;
	voteurs.resize(nb_voteurs+1);

	for (int i(0); i < nb_voteurs; ++i)
	{
		ll m, p;
		cin >> m >> p;
		voteurs[m].push_back(p);
	}

	priority_queue<int> a_acheter;

	ll tot(0);

	for (int i(nb_voteurs); i > 0; --i)
	{
		for (auto v : voteurs[i])
			a_acheter.push(-v);

		while (nb_voteurs - a_acheter.size() < i)
		{
			tot += -a_acheter.top();
			a_acheter.pop();
		}
		}
	return tot;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int q;
	cin >> q;
	while (q--)
		pnl(solve());
}