#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(i, j, n) for (int i(j); i < (n); ++i)
#define FORR(v, c) for (auto &v : (c))
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x, y, z) cin >> x >> y >> z
#define read4(a, b, c, d) cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

typedef	vector<int>	vi;
typedef vector<long long>	vl;
typedef	long long ll;

const int MAXN = 2e5;

vector<int> rG[MAXN];
set<int> to_visit;
int nb_sommets, nb_aretes;
int sz;

void dfs(int u)
{
	sz++;
	sort(all(rG[u]));
	rG[u].push_back(nb_sommets);
	int lst(-1);
	for (auto up : rG[u])
	{
		set<int>::iterator it;
		while ((it=to_visit.upper_bound(lst)) != to_visit.end() and *it < up)
		{
			int v = *it;
			to_visit.erase(it);
			dfs(v);
		}
		lst=up;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	read2(nb_sommets, nb_aretes);
	for (int i(0); i < nb_aretes; ++i)
	{
		int u, v;
		read2(u,v);
		--u, --v;
		rG[u].pb(v);
		rG[v].pb(u);
	}
	FOR(i,0,nb_sommets)
		to_visit.insert(i);
	vi cc;
	while (SZ(to_visit))
	{
		sz=0;
		int s = *to_visit.begin();
		to_visit.erase(s);
		dfs(s);
		cc.pb(sz);
	}
	sort(all(cc));
	pnl(SZ(cc));
	FORR(v,cc) pns(v);
	cout<<endl;
}