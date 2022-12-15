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

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

class Fenwick
{
	public :
		
		Fenwick(void)
		{

		}

		Fenwick(int n)
		{
			BIT.resize(n+1);
			N = n;
			fill(all(BIT), 0);
		}

		void update(int x, int delta)
		{
			x++;
			for (; x <= N; x += x &-x)
				BIT[x] += delta;
		}

		ll query(int x) const
		{
			x++;
			ll sum = 0;
			for (; x > 0; x -= x&-x)
				sum += BIT[x];
			return sum;
		}

	private:
		vector<ll> BIT;
		int N;
};

const int MAXN = 2e5;

ll n, T;
vector<ll> prices;
Fenwick fen;

int find_first_block(void)
{
	int left(0), right(n-1);

	while (left < right)
	{
		int mid = (left + right) /2;
		ll sum = fen.query(mid);
		if (sum <= T)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	read2(n, T);		
	fen = Fenwick(n);		

	prices.resize(n);
	readv(prices);
	FOR(i,0,n)
		fen.update(i, prices[i]);
	ll ans(0);
	int left(n);
	while (left>0)
	{
//		cout << "Money left : " << T << endl;
		ll total_price = fen.query(n-1);
		if (total_price <= T)
		{
			ans += left * (T/total_price);
			T %= total_price;
		}
		else
		{
			int to_rem = find_first_block();
//			cout << "Removed :" << to_rem << endl;
			left--;
			fen.update(to_rem, -prices[to_rem]);
			prices[to_rem] = 0;
		}
	}
	cout << ans << endl;
}