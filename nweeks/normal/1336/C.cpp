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

const ll MOD = 998244353;
const int MAXN = 5000;
ll ways[MAXN][MAXN];

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	string start, target;
	cin >> start;
	cin >> target;
	int len_start(SZ(start));
	int len_target(SZ(target));

	
	FOR(i, 0, len_target)
		if (start[0] == target[i])
			ways[i][i] = 2;
	FOR(i, len_target, len_start)
		ways[i][i] = 2;
	for (int diff(1); diff < len_start; ++diff)
		for (int lft(0); lft+diff<= len_start; ++lft)
		{
			int rgt = lft + diff-1;
			if (lft > len_target or (lft > 0 and target[lft-1] == start[diff]))
				ways[lft-1][rgt] = (ways[lft-1][rgt] + ways[lft][rgt])%MOD;
			if (rgt >= len_target-1 or target[rgt+1] == start[diff])
				ways[lft][rgt+1] = (ways[lft][rgt+1] + ways[lft][rgt])%MOD;
		}
	ll ans(0);
	FOR(r, SZ(target)-1, SZ(start))
		ans = (ans + ways[0][r])%MOD;
	cout << ans << endl;
}