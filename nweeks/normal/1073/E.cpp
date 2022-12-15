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

const ll MOD = 998244353;

ll ans(0);
const int MAXMASK = (1<<10);
const int MAXDIGIT = 20;
const int MAXSTATES = 2;

ll dp_count[MAXDIGIT][MAXMASK][MAXSTATES];
ll dp_sum[MAXDIGIT][MAXMASK][MAXSTATES];
ll powers[MAXDIGIT];
vector<int> number;
int k;

pair<long, long> compute(int cur_digit, int cur_mask, bool under)
{
	int size_mask = __builtin_popcount(cur_mask);
	if (size_mask > k) return {0, 0};
	if (cur_digit == number.size())
		return make_pair(1, 0);
	if (dp_count[cur_digit][cur_mask][under] != -1)
		return make_pair(dp_count[cur_digit][cur_mask][under], dp_sum[cur_digit][cur_mask][under]);
	dp_count[cur_digit][cur_mask][under] = 0;	
	dp_sum[cur_digit][cur_mask][under] = 0;	
	for (int digit(0); digit < (under ? 10 : number[cur_digit]+1); ++digit)
	{
		int nmask;
		if (cur_mask == 0 and digit == 0) nmask = 0;
		else nmask = cur_mask | (1<<digit);
		auto ans = compute(cur_digit + 1, nmask, under | (digit<number[cur_digit]));
		dp_count[cur_digit][cur_mask][under] += ans.first;
		dp_count[cur_digit][cur_mask][under] %= MOD;
		dp_sum[cur_digit][cur_mask][under] += (ans.second+ (((digit*powers[number.size()-1-cur_digit])%MOD)*ans.first))%MOD;
		dp_sum[cur_digit][cur_mask][under] %= MOD;
	}
	return make_pair(dp_count[cur_digit][cur_mask][under], dp_sum[cur_digit][cur_mask][under]);
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll cur(1);
	FOR(i,0,MAXDIGIT)
	{
		powers[i] = cur;
		cur *= 10;
		cur %= MOD;
	}
	FOR(i,0,MAXDIGIT) FOR(j,0,MAXMASK) FOR(k,0,MAXSTATES)
		dp_count[i][j][k] = dp_sum[i][j][k] = -1;

	ll l, r;
	read3(l, r, k);
	l--;
	do
	{
		number.push_back(l%10);
		l/=10;
	} while(l);
	for (int i(0); number.size()-1-i>i; ++i)
		swap(number[i], number[number.size()-1-i]);

	ll bef = (MOD  -compute(0, 0, false).second)%MOD;
	
	number.clear();
	while (r)
	{
		number.push_back(r%10);
		r /= 10;
	}
	for (int i(0); number.size()-1-i>i; ++i)
		swap(number[i], number[number.size()-1-i]);
	FOR(i,0,MAXDIGIT) FOR(j,0,MAXMASK) FOR(k,0,MAXSTATES)
		dp_count[i][j][k] = dp_sum[i][j][k] = -1;
	ll after = compute(0,0,false).second;
//	cout << bef << ' ' << after << endl;
	cout << (after + bef)%MOD << endl;
}