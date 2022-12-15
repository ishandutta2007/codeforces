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

const int MAXN = 1e6;

Mint fact[MAXN], invfact[MAXN];

void calcfact(void)
{
	fact[0] = invfact[0] = 1;
	for (int i(1); i < MAXN; ++i)	
	{
		fact[i] = i * fact[i-1];
		invfact[i] = 1/fact[i];
	}
}

Mint binom(int n, int k)
{
	return fact[n] * invfact[k] * invfact[n-k];
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	calcfact();
	Mint ans(0);
	if (k == 1)
	{
		cout << n << endl;
		return 0;
	}
	for (int i(1); i <= n; ++i)
	{
		int nb_multiples = n/i - 1;
		if (nb_multiples < k-1)
			continue ;
		ans += binom(nb_multiples, k-1);
	}	
	cout << ans << endl;
}