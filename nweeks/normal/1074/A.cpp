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

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int nb_verti, nb_hori;
	read2(nb_verti, nb_hori);

	vi vert(nb_verti);
	readv(vert);
	sort(all(vert));

	vi hori;
	FOR(i,0, nb_hori)
	{
		int x1, x2, y;
		read3(x1, x2, y);
		if (x1 != 1) continue ;
		hori.pb(x2);
	}
	sort(all(hori));

	int ans(1e9);
	int r(0);
	for (int i(0); i < nb_verti; ++i)
	{
		while (r < hori.size() and hori[r] < vert[i]) ++r;
		ans = min(i + ((int)hori.size() - r), ans);
	}
	while (r < hori.size() and hori[r] < 1e9) ++r;
		ans = min(nb_verti + ((int)hori.size()  -r), ans);
	
	pnl(ans);
}