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

const int MAXN = 101;

ll dp[MAXN][MAXN][MAXN];
vi reward;
int n;
string s;

ll solve(int start, int end, int taken)
{
	if (start >= n or end < start)
		return 0;
	if (dp[start][end][taken]!=-1)
		return dp[start][end][taken];
	ll &cur = dp[start][end][taken];
	cur = solve(start+1, end, 0) + reward[taken];	
	for (int nxt(start+1); nxt <= end; ++nxt)
		if (s[start] == s[nxt])
			cur = max(cur, solve(start+1, nxt-1, 0) + solve(nxt,end,taken+1));
	return cur;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	read(n);
	read(s);
	reward.resize(n);
	readv(reward);
	FOR(start,0,n) FOR(end, 0, n) FOR(taken,0,n)
		dp[start][end][taken] = -1;

	cout << solve(0,n-1, 0) << endl;
}