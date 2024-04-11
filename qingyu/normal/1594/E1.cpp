#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

const int N = 1e6 + 50;


ll f[N], g[N];
map<string, int> conv;
long long k, n, v[N], col[N];

ll fp(ll x, ll p, const int mod = ::mod)
{
	ll r = 1;
	while (p)
	{
		if (p & 1) r = r * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return r;
}

ll mlog(ll x)
{
	ll t = 1, k = 0;
	while (t <= x)
	{
		t <<= 1;
		++k;
	}
	return k;
}


int type(long long x, long long y)
{
	int last = -1;
	while (y > x)
	{
		last = y & 1;
		y >>= 1;
	}
	assert(last != -1);
	//printf("last = %d\n", last);
	return last;
}


tuple<ll, ll, ll> dfs(ll x, vector<int> vec)
{
	//printf("dfs %lld\n", x);
	if (vec.empty())
	{
		ll z = k - mlog(x);
		if (z == -1) return make_tuple(1, 1, 1);
		assert(z >= 0);
		ll nodes = (fp(2, k - mlog(x) + 1, mod - 1) - 1 + mod - 1) % (mod - 1);
		ll t =  fp(2, (2 * nodes - 1 + mod - 1) % (mod - 1));
		return make_tuple(t, t, t);
	}
	else
	{
		vector<int> _[2];
		int cons = -1;
		for (int y : vec)
		{
			if (x != v[y])
			{
				_[type(x, v[y])].push_back(y);
			}
			else
			{
				cons = col[y];
			}
		}
		ll c1[3], c2[3], s1, s2, ans[3];
		if ((x << 1) >= (1ll << k))
		{
			for (int i = 0; i < 3; ++i)
				if (cons == -1 || i == (cons >> 1))
					ans[i] = 1;
				else
					ans[i] = 0;
			if (cons == -1) for (int i = 0; i < 3; ++i) ans[i] = (ans[i] * 2) % mod;
		}
		else
		{
			auto [x1, y1, z1] = dfs(x << 1, _[0]); 
			auto [x2, y2, z2] = dfs(x << 1 | 1, _[1]);
			c1[0] = x1, c1[1] = y1, c1[2] = z1;
			c2[0] = x2, c2[1] = y2, c2[2] = z2;
			s1 = (c1[0] + c1[1] + c1[2]) % mod;
			s2 = (c2[0] + c2[1] + c2[2]) % mod;
			//printf("s1 = %lld, s2 = %lld\n", s1, s2);	
			for (int i = 0; i < 3; ++i)
				if (cons == -1 || i == (cons >> 1))
					ans[i] = (s1 - c1[i] + mod) * (s2 - c2[i] + mod) % mod;
				else
					ans[i] = 0;
			if (cons == -1)
			{
				for (int i = 0; i < 3; ++i)
					ans[i] = (ans[i] * 2) % mod;
			}
		}
		//printf("x = %lld, ans = %lld %lld %lld\n", x, ans[0], ans[1], ans[2]);
		return make_tuple(ans[0], ans[1], ans[2]);
	}
	return make_tuple(0, 0, 0);
}

int main()
{
//	for (int i = 1; i <= 100; ++i) printf("mlog(%d) = %lld\n", i, mlog(i));
	ios::sync_with_stdio(false);
	cin >> k;
	conv["white"] = 0, conv["yellow"] = 1;
	conv["green"] = 2, conv["blue"] = 3;
	conv["red"] = 4, conv["orange"] = 5;
	n = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		string s;
		cin >> s;
		col[i] = conv[s];
	}
	f[0] = 1, g[0] = 0;
	for (int i = 1; i <= 2000; ++i)
	{
		f[i] = (2 * f[i - 1] + 2 * g[i - 1]) % mod;
		g[i] = (4 * f[i - 1]) % mod;
	}
	vector<int> vec;
	for (int i = 1; i <= n; ++i) vec.push_back(i);
	auto [x, y, z] = dfs(1, vec);
	cout << (x + y + z + mod + mod) % mod << '\n';
}