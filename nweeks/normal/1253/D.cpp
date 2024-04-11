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

struct Arete { int v, c;};
struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

typedef	vector<int>	vi;
typedef pair<int,int>	ii;
typedef vector<string>	vs;
typedef vector<ii>	vii;
typedef vector<Arete>	vg;
typedef vector<long long>	vl;
typedef	long long ll;

const int MAXN = 2e5;

int id[MAXN];
int first[MAXN], last[MAXN];

int find(int i)
{
	if (id[i] == i)
		return i;
	return id[i] = find(id[i]);
}

void merge(int i, int j)
{
	i = find(i), j = find(j);

	first[i] = min(first[i], first[j]);
	last[i] = max(last[i], last[j]);
	id[j] = i;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, m;
	read2(n,m);
	FOR(i,0,n) id[i] = first[i] = last[i] = i;
	FOR(i,0,m)
	{
		int u, v;
		read2(u, v);
		merge(u-1, v-1);
	}
	int ans(0);
	
	vi cc;

	for (int i(0); i < n; ++i)
	{
		int c = find(i);
		int beg = first[c], en = last[c];
		
		if (cc.size() == 0)
		{
			cc.pb(c);
			continue;
		}
		int sz = cc.size();
		while (cc.size() > 0 and c != cc[sz-1] and last[cc[sz-1]] > first[c])
		{
			merge(c, cc[sz-1]);
			ans++;
			sz--;
			cc.pop_back();
		}
		if (not (cc.size() > 0 and c == cc[sz-1]))
			cc.pb(c);
	}
	cout << ans << endl;
}