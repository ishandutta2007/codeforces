#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

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

using Mint = ModInt<998244353>;

const int MOD = 998244353;
const int MAXFACT = 1e6+1;
Mint fact[MAXFACT], invFact[MAXFACT];
void init(void)
{
	fact[0] = invFact[0] = 1;
	for (int i(1); i < MAXFACT; ++i)
	{
		fact[i] = i * fact[i-1];
		invFact[i] = 1/fact[i];
	}
}

Mint binom(int n, int k)
{
	return fact[n] * invFact[n-k] * invFact[k];
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;

	Mint ans(0);
	init();

	// calc A : 
	for (int k(1); k <= n; ++k)
	{
		Mint sign((k+1)%2 ? MOD-1 : 1);
		ans += 2 * sign * Mint(3).fastpow(k + n * (n-k)) * binom(n, k);
	}	

	// Calc B :
	for (int j(0); j < n; ++j)
	{
		Mint sign((j+1)%2 ? MOD-1 : 1);
		Mint sign2(n%2 ? MOD-1 : 1);
		ans += 3 * sign * binom(n, j) * ( (1 - Mint(3).fastpow(j)).fastpow(n) - sign2 * Mint(3).fastpow(n*j));
	}
	cout << ans << endl;
}