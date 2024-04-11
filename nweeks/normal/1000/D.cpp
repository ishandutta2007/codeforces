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

const int MAX = 1e3+1;
const int MOD = 998244353;

ll dp[MAX];
ll pascal[MAX][MAX];

void run_pascal(void)
{
	FOR(i,0,MAX)
		pascal[i][i] = pascal[i][0] = 1;
	FOR(i,1,MAX)
		FOR(j, 1, i)
			pascal[i][j] = (pascal[i-1][j] + pascal[i-1][j-1])%MOD;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	read(n);
	vl numbers(n);
	readv(numbers);
	run_pascal();
	
	dp[n] = dp[n-1] = 0;
	for (int i(n-2); i >= 0; --i)
	{
		if (numbers[i] <= 0) {dp[i] = dp[i+1]; continue ;}
		if (i + numbers[i] >= n) {dp[i] = dp[i+1]; continue;}
		for (int j(i + numbers[i]+1); j <= n; ++j)
			dp[i] = (dp[i] + (pascal[j-2-i][numbers[i]-1] * (1+dp[j]))%MOD)%MOD;
		dp[i] = (dp[i] + dp[i+1])%MOD;
	}

	pnl(dp[0]);
}