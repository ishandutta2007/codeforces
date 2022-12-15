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

const int MAXC = 20;

ll cost[MAXC][MAXC];
ll dp[1<<MAXC];
vector<int> pos[MAXC];

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> arr(n);
	readv(arr);
	FORR(v,arr) --v;
	FOR(i,0,n)
		pos[arr[i]].pb(i);

	for (int col_left(0); col_left < MAXC; ++col_left)
		for (int col_right(0); col_right<MAXC; ++col_right)
			if (col_right != col_left)
			{
				int i_right(0), i_left(0);
				while (i_left < SZ(pos[col_left]))
				{
					while (i_right< SZ(pos[col_right]) and pos[col_right][i_right]<pos[col_left][i_left])
						++i_right;
					cost[col_left][col_right] += i_right;
					++i_left;
				}
			}

	for (int mask(0); mask < (1<<MAXC); ++ mask)
		dp[mask] = 8e18;
	dp[0] = 0;
	for (int mask(0); mask < (1<<MAXC); ++mask)
		for (int nxt_col(0); nxt_col < MAXC; ++nxt_col)
			if (((1<<nxt_col)&mask)==0)
			{
				ll cst(0);
				for (int c(0); c < MAXC; ++c)
					if ( ((1<<c)&mask)==0 and c != nxt_col)
						cst += cost[nxt_col][c];
				dp[mask|(1<<nxt_col)] = min(dp[mask|(1<<nxt_col)], cst+dp[mask]);
			}
	cout << dp[(1<<MAXC)-1] << endl;
}