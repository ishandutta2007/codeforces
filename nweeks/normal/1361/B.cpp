#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

ll solve(void);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tests;
	cin >> nb_tests;

	for (int i(0); i < nb_tests; ++i)
		solve();
}

template<const int32_t MOD>
struct ModInt {
	long long x;
	ModInt() : x(0) {}
	ModInt(long long u) : x(u) {}
	ModInt& operator = (const ModInt &m) { x = m.x; return *this; }
	friend bool operator == (const ModInt& a, const ModInt& b) { return a.x == b.x; }
	friend bool operator != (const ModInt& a, const ModInt& b) { return a.x != b.x; }
	friend bool operator < (const ModInt& a, const ModInt& b) { return a.x < b.x; }
	friend bool operator > (const ModInt& a, const ModInt& b) { return a.x > b.x; }
	friend bool operator <= (const ModInt& a, const ModInt& b) { return a.x <= b.x; }
	friend bool operator >= (const ModInt &a, const ModInt& b) { return a.x >= b.x; }
	static ModInt sign(long long k) { return ((k & 1) ? ModInt(MOD-1) : ModInt(1)); }

 
	ModInt& operator += (const ModInt& m) { x += m.x; if(x >= MOD) x -= MOD; return *this; }
	ModInt& operator -= (const ModInt& m) { x -= m.x; if(x < 0LL) x += MOD; return *this; }
	ModInt& operator *= (const ModInt& m) { x = (1LL * x * m.x) % MOD; return *this; }
	
	friend ModInt operator - (const ModInt& a) { ModInt res(a); if(res.x) res.x = MOD - res.x; return res; }
	friend ModInt operator + (const ModInt& a, const ModInt& b) { return ModInt(a) += ModInt(b); }
	friend ModInt operator - (const ModInt& a, const ModInt& b) { return ModInt(a) -= ModInt(b); }
	friend ModInt operator * (const ModInt& a, const ModInt& b) { return ModInt(a) *= ModInt(b); }
	
	static long long fp(long long u, long long k) {
		long long res = 1LL;
		while(k > 0LL) {
			if(k & 1LL) res = (res * u) % MOD;
			u = (u * u) % MOD;
			k /= 2LL;
		}
		return res;
	}
	
	ModInt fastpow(long long k) { return ModInt(fp(x, k)); }
	ModInt inv() { return ModInt(fp(x, MOD-2)); }
	ModInt& operator /= (const ModInt& m) { return *this *= ModInt(m).inv(); }
	friend ModInt operator / (const ModInt& a, const ModInt& b) { return ModInt(a) *= ModInt(b).inv(); }
 
	friend ostream& operator << (ostream& out, const ModInt& a) { return out << a.x; }
};

using Mint = ModInt<(int)(1e9) +7>;
int n, p;

Mint calcAns(vector<int> powers)
{
	vector<pair<int, int>> condensed;

	for (auto c : powers)
	{
		if (SZ(condensed)==0 or condensed.back().first != c)
			condensed.emplace_back(c, 1);
		else
			condensed.back().second++;
	}

	stack<pair<int, int>> after;

	while (SZ(condensed))
	{
		auto [c, cnt] = condensed.back();
		condensed.pop_back();
		if (after.empty())
		{
			if (cnt%2)
				after.push({c, 1});
			continue;
		}
		if (cnt < p)
		{
			after.push({c, cnt});
			continue;
		}
		cnt -= p;
		if (cnt > 0)
			condensed.push_back({c, cnt});

		if (after.top().first!= c+1)
			after.push({c+1, 1});
		else
		{
			auto [cAfter, cntAfter] = after.top(); after.pop();
			cntAfter++;
			condensed.emplace_back(cAfter, cntAfter);
		}
	}
	if (SZ(after) == 0)
		return 0;
	Mint lft(0);
	while (SZ(after) > 1)
	{
		auto [c, cnt] = after.top(); after.pop();
		lft += cnt * Mint(p).fastpow(c);
	}
	Mint rgt(0);
	auto [c, cnt] = after.top(); after.pop();
	rgt = cnt * Mint(p).fastpow(c);
	return rgt - lft;
}

ll solve(void)
{
	cin >> n >> p;

	vector<int> powers(n);
	for (auto &v : powers)
		cin >> v;
	sort(powers.begin(), powers.end());
	if (p == 1)
	{
		cout << n%2 << '\n';
		return 0;
	}

	cout << calcAns(powers) << '\n';
	return 0;
}