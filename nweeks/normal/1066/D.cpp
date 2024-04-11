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

int sizes[MAXN];
int nb_objets, nb_boites, taille_boite;

bool ok(int start)
{
	int boxes_left(nb_boites);
	int space_left(0);
	for (int i(start); i < nb_objets; ++i)
	{
		if (space_left < sizes[i])
			space_left = taille_boite, boxes_left--;
		if (boxes_left < 0)
			return false;
		space_left -= sizes[i];
	}
	return true;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> nb_objets >> nb_boites >> taille_boite;
	FOR(i,0,nb_objets)
		read(sizes[i]);
	int left(0), right(nb_objets-1);
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (ok(mid))
			right = mid;
		else
			left = mid+1;
	}
	cout << nb_objets - left << endl;
}