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

const int MAX = 1e5;
int group[MAX];
map<string, int> id;
int cost_group[MAX];
int cost_word[MAX];
string words[MAX];

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int N, k, m;
	read3(N, k, m);
	FOR(i,0,k)
		cost_group[i] = 1e9;
	
	FOR(i,0,N)
	{
		cin >> words[i];
		id[words[i]] = i;
	}
	
	FOR(i,0,N)
		cin >> cost_word[i];
	FOR(i,0,k)
	{
		int n; read(n);
		for (int k(0); k < n; ++k)
		{
			int iden; read(iden);
			--iden;
			group[iden] = i;
			cost_group[i] = min(cost_group[i], cost_word[iden]);
		}
	}
	ll ans(0);
	for (int i(0); i < m; ++i)
	{
		string w; read(w);
		ans += cost_group[group[id[w]]];
	}
	pnl(ans);
}