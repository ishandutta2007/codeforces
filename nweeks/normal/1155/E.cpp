#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const ll MOD = 1e6+3;

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

Mint ask_question(int x)
{
	cout << "? " << x << endl;
	cout.flush();
	int ret;
	cin >> ret;
	return Mint(ret);
}

vector<Mint> multiply_pol(const vector<Mint> &A, const vector<Mint> &B)
{
	vector<Mint> ret(SZ(A) + SZ(B));
	for (int i(0); i < SZ(A); ++i)
		for (int j(0); j < SZ(B); ++j)
			ret[i+j] += A[i]*B[j];
	return ret;	
}

vector<Mint> mult(const vector<Mint> &A, Mint l)
{
	return multiply_pol(A, vector<Mint>({l}));
}

vector<Mint> add_pol(const vector<Mint> &A, const vector<Mint> &B)
{
	vector<Mint> ret(max(SZ(A), SZ(B)), Mint(0));
	for (int i(0); i < SZ(A); ++i)
		ret[i] += A[i];
	for (int i(0); i < SZ(B); ++i)
		ret[i] += B[i];
	return ret;
}

Mint eval(Mint x, const vector<Mint> &pol)
{
	Mint ret = Mint(0);
	for (int i(SZ(pol)-1); i >= 0; --i)
		ret = ret * x + pol[i];
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	const int deg = 10;
	vector<Mint> p = {Mint(1000002), Mint(0), Mint(1)};
	vector<Mint> val(deg+1);
	for (int i(0); i <= deg; ++i)
		val[i] = ask_question(i);

	vector<Mint> pol(1);
	for (int i(0); i <= deg; ++i)
	{
		vector<Mint> monome(1, Mint(1));
		for (int j(0); j <= deg; ++j)
		if (j != i)
			monome = multiply_pol(monome, mult({Mint(-j), Mint(1)}, Mint(1)/Mint(i-j)));
		monome = mult(monome, val[i]);		
		pol = add_pol(pol, monome);
	}
	for (int i(0); i < MOD; ++i)
		if (eval(Mint(i), pol) == Mint(0))
		{
			cout << "! " << i << endl;
			cout.flush();
			return 0;
		}
	cout << "! -1" << endl;
	cout.flush();
}