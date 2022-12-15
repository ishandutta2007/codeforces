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

map<pair<pair<int,int>, bool>, ll> dp;

ll solve(int lo, int up, bool parity)
{
	if (lo > up) return 1;
	if (dp.count({{lo,up}, parity}))
		return dp[{{lo,up},parity}];
	set<int> roots;
	roots.insert((lo+up)/2);
	roots.insert((lo+up+1)/2);
	for (int root : roots)
	{
		if (root%2==parity)
			dp[{{lo,up},parity}] += solve(lo, root-1, !parity) * solve(root+1,up,parity);
	}
	return dp[{{lo,up},parity}]%MOD;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	cout << solve(1, n, n%2)<<endl;
}