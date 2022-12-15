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

const int MAXTAKE = 8;
const int MAXN = 3e5+1;
ll binom[MAXN][MAXTAKE];
ll nb_occ[MAXN];
ll dp[MAXTAKE][MAXN];
int nb_elem;
ll nb_multiples[MAXN];
ll arr[MAXN];

void calc_binom(void)
{
	for (int lig(0); lig < MAXN; ++lig)
	{
		binom[lig][0] = 1;
		if (lig < MAXTAKE)
			binom[lig][lig] = 1;
		for (int col(1); col < min(MAXTAKE, lig); ++col)
			binom[lig][col] = binom[lig-1][col-1] + binom[lig-1][col];
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	calc_binom();
	cin >> nb_elem;
	FOR(i,0, nb_elem)
	{
		cin >> arr[i];
		nb_occ[arr[i]]++;
	}
	for (int i(1); i < MAXN; ++i)
		for (int j(i); j < MAXN; j += i)
			nb_multiples[i] += nb_occ[j];

	for (int take(1); take < MAXTAKE; ++take)
	{
		for (int val(MAXN-1); val >= 1; --val)
		{
			dp[take][val] = binom[nb_multiples[val]][take];
			for (int j(2*val); j < MAXN; j += val)
				dp[take][val] -= dp[take][j];
		}
		if (dp[take][1])
		{
			cout<<take<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}