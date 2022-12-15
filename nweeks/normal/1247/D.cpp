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

const int MAX = 1e5 + 1;

bool is_prime[MAX];

int cnt[MAX];
vector<ii> decomp[MAX];

vi primes;

void gen(void)
{
	FOR(i,2, MAX)
		is_prime[i] = true;

	FOR(i, 2, MAX)
		if (is_prime[i])
		{
			primes.pb(i);
			for (int j(2*i); j < MAX; j += i)
				is_prime[j] = false;
		}
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	gen();

	int n, k;
	read2(n, k);
	vi a(n);
	readv(a);
	
	ll ans(0);
	
	FOR(i,0, n)
	{
		int cur = a[i];
		int p = 0;
		while (cur > 1)
		{
			if (cur % primes[p] == 0)
			{
				int expo = 0;
				while (cur and cur % primes[p] == 0)
					expo++, cur /= primes[p];
				expo %= k;
				if (expo != 0)
					decomp[i].pb({primes[p], expo});
			}
			p++;
		}
		ll nb= 1;
		ll need = 1;
		FORR(v, decomp[i])
		{
			int expo = v.second;
			int p = v.first;
			while (expo)
				expo--, nb *=p;
			expo = k - v.second;
			while (expo && need < MAX)
				expo--, need *= p;
			
		}
		if (need < MAX)
			ans += cnt[need];
		cnt[nb]++;
	}
	pnl(ans);
	}