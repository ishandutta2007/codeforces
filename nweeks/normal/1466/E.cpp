#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

template<const int32_t MOD>
struct ModInt {
	long long x;
	ModInt() : x(0) {}
	ModInt(long long u) : x(u) { x %= MOD; if (x < 0) x += MOD;}
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

using Mint = ModInt<MOD>;
const int MAXBIT = 60;
const int MAXN = 5e5;

ll vals[MAXN];
int cnt[MAXBIT];

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int nbElem;
		cin >> nbElem;
		for (int i(0); i < nbElem; ++i)
			cin >> vals[i];
		for (ll bit(0); bit < MAXBIT; ++bit)
		{
			cnt[bit] = 0;
			for (int i(0); i < nbElem; ++i)
				cnt[bit] += !!((1LL<<bit) & vals[i]);
		}
		vector<Mint> calcSum(nbElem);
		for (int i(0); i < nbElem; ++i)
			for (ll bit(0); bit < MAXBIT; ++bit)
				calcSum[i] += Mint(1LL<<bit) * ( ((1LL<<bit)&vals[i]) ? nbElem : cnt[bit]);
		Mint ret(0);
		for (int i(0); i < nbElem; ++i)
			for (ll bit(0); bit < MAXBIT; ++bit)
				if ((1LL<<bit) & vals[i])
					ret += Mint(1LL<<bit) * cnt[bit] * calcSum[i];
		cout << ret << '\n';
	}
}