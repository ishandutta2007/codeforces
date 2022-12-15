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

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbJoueurs;
	cin >> nbJoueurs;

	vector<int> nbBonbons(nbJoueurs);
	Mint sommeBonbons(0);
	for (int i(0); i < nbJoueurs; ++i)
	{
		cin >> nbBonbons[i];
		sommeBonbons += nbBonbons[i];
	}

	vector<Mint> potentiel(sommeBonbons.x + 1);
	for (int i(1); i < sommeBonbons; ++i)
	{
		potentiel[i+1] = (sommeBonbons * (nbJoueurs-1))/(sommeBonbons - i);
		potentiel[i+1] *= potentiel[i] - i/sommeBonbons * (potentiel[i-1] + 1) - (nbJoueurs -2) * (sommeBonbons - i) / (sommeBonbons * (nbJoueurs-1)) * potentiel[i];
	}

	Mint rep(0);
	for (int i(0); i < nbJoueurs; ++i)
		rep += potentiel[nbBonbons[i]];
	rep -= potentiel[sommeBonbons.x];
	cout << rep << endl;
}