#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXN = 101;
const int MAXSUM = MAXN * MAXN;

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

using Mint = ModInt<(int)1e9+7>;

Mint nbFacons[MAXN][MAXSUM];
int nbOcc[MAXN];

vector<int> poids;


const int MAXFACT = 101;
Mint fact[MAXFACT], invFact[MAXFACT];
void init(void)
{
	fact[0] = invFact[0] = 1;
	for (int i(1); i < MAXN; ++i)
	{
		fact[i] = i * fact[i-1];
		invFact[i] = 1/fact[i];
	}
}

Mint binom(int n, int k)
{
	return fact[n] * invFact[n-k] * invFact[k];
}

void precalc(void)
{
	nbFacons[0][0] = 1;
	for (int id(0); id < SZ(poids); ++id)
		for (int i(SZ(poids)); i >= 1; --i)
			for (int j(MAXSUM-1); j >= poids[id]; --j)
				nbFacons[i][j] += nbFacons[i-1][j - poids[id]];
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbPoids;
	cin >> nbPoids;
	int totalSum(0);
	for (int i(0); i < nbPoids; ++i)
	{
		int w;
		cin >> w;
		poids.push_back(w);
		nbOcc[w]++;
		totalSum += w;
	}

	int nbDiff(0);
	for (int i(1); i <= 100; ++i)
		nbDiff += !!nbOcc[i];
	if (nbDiff <= 2)
	{
		cout << nbPoids;
		cout << endl;
		return 0;
	}

	init();
	precalc();

	int ans(1);
	for (int i(1); i <= 100; ++i)
		for (int take(nbOcc[i]); take > ans; --take)
			if (nbFacons[take][take * i] == binom(nbOcc[i], take))
				ans = take;
	for (int i(1); i <= 100; ++i)
		for (int take(nbOcc[i]); take > ans; --take)
			if (nbFacons[nbPoids - take][totalSum - take * i] == binom(nbOcc[i], take))
				ans = take;

	cout << ans << endl;
}