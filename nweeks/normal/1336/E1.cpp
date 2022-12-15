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

const int MAXB = 36;
const int MAXN = 2e5;
const ll MOD = 998244353;  

ll arr[MAXN];
ll base[MAXB];
ll sol[MAXB];
int ways[2][1<<17][MAXB];
vector<ll> used_bits, unused_bits;
int n, m;

void build_base(void)
{
	for (int i(0); i < n; ++i)
	{

		for (ll b(m-1); b>= 0; --b)
		{
			ll bit = (1LL<<b);
			if (bit & arr[i])
			{
				if (base[b])
					arr[i] ^= base[b];
				else
				{
					base[b] = arr[i];
					break;
				}
			}
		}
	}
	for (ll i(0); i < m; ++i)
		if (base[i])
			for (int j(i+1); j < m; ++j)
				if ((1LL<<i) & base[j])
					base[j] ^= base[i];
}

ll powmod(ll a, ll b)
{
	ll p(a), ret(1);
	while (b)
	{
		if (b%2) ret = (ret*p)%MOD;
		p = (p*p)%MOD;
		b/=2;
	}
	return ret;
}

void  brute_force(void)
{
	for (int mask(0); mask < (1<<SZ(used_bits)); ++mask)
	{
		ll x=0;
		for (int i(0); i < SZ(used_bits); ++i)
			if ((1<<i)&mask)
				x ^= base[used_bits[i]];
		++sol[__builtin_popcountll(x)];
	}
}

void comp(void)
{
	vector<int> new_base(SZ(used_bits));
	for (int i(0); i < SZ(used_bits);++i)
	{
		new_base[i] = 0;
		for (int j(0); j < SZ(unused_bits); ++j)
			if ((1LL<<unused_bits[j])&base[used_bits[i]])
				new_base[i] += 1<<j;
	}

	ways[0][0][0] = 1;
	for (int used(0); used < SZ(used_bits); ++used)
	{
		int cur=used%2;
		int nxt= !cur;
		for (int mask(0); mask < (1<<SZ(unused_bits));++mask)
			for (int cnt_main(0); cnt_main <= used+1; ++cnt_main)
				ways[nxt][mask][cnt_main]=0;
		for (int mask(0); mask < (1<<SZ(unused_bits)); ++mask)
			for (int cnt_main(0); cnt_main <= used; ++cnt_main)
			{
				ways[nxt][mask][cnt_main] = (ways[nxt][mask][cnt_main]
												+ways[cur][mask][cnt_main])%MOD;
				ways[nxt][mask^new_base[used]][cnt_main+1]
								= (ways[nxt][mask^new_base[used]][cnt_main+1]
											+ ways[cur][mask][cnt_main])%MOD;
			}
	}
	for (int mask(0); mask < (1<<SZ(unused_bits)); ++mask)
		for (int cnt_main(0); cnt_main <= SZ(used_bits); ++cnt_main)
		{
			ll add = ways[SZ(used_bits)%2][mask][cnt_main];
			ll nb_bits = __builtin_popcountll(mask) + cnt_main;
			sol[nb_bits] = (sol[nb_bits] + add)%MOD;
		}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i(0); i < n; ++i)
		cin >> arr[i];

	build_base();
	
	for (int i(0); i < m; ++i)
	{
		if (base[i])
			used_bits.push_back(i);
		else
			unused_bits.push_back(i);
	}

	if (SZ(used_bits)<=18)
		brute_force();
	else
		comp();

	ll mult = powmod(2, n-SZ(used_bits));
	for (int i(0); i <= m; ++i)
		sol[i] = sol[i]*mult%MOD;
	for (int i(0); i <= m; ++i)
		pns(sol[i]);
	cout<<endl;
}