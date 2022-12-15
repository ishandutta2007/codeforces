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

const int MAXN = 5e5;

bool basis[MAXN];
int toAdd[MAXN];
vector<int> bits[MAXN];

int find(int u)
{
	if (u == -1)
		return -1;
	if (!basis[u])
		return u;
	return toAdd[u] = find(toAdd[u]);
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int nbVecteurs, dim;
	cin >> nbVecteurs >> dim;
	for (int i(0); i < dim; ++i)
	{
		basis[i] = false;
		toAdd[i] = -1;
	}
	
	for (int i(0); i < nbVecteurs; ++i)
	{
		int nbBits;
		cin >> nbBits;
		bits[i].resize(nbBits);
		for (int j(0); j < nbBits; ++j)
		{
			cin >> bits[i][j];
			--bits[i][j];
		}
		if (bits[i].back() > bits[i].front())
			swap(bits[i][0], bits[i][1]);
		if (nbBits == 2 and bits[i][0] == bits[i][1])
			bits[i].clear();
	}
	vector<int> ans;
	for (int i(0); i < nbVecteurs; ++i)
	{
		while (!bits[i].empty() and basis[bits[i].back()])
		{
			bits[i].back() = find(bits[i].back());
			if (bits[i].back() == -1)
				bits[i].pop_back();
			else if (bits[i].back() > bits[i].front())
				swap(bits[i][0], bits[i][1]);
			else if (SZ(bits[i]) > 1 and bits[i][0] == bits[i][1])
				bits[i].clear();
		}
		if (bits[i].empty())
			continue ;
		basis[bits[i].back()] = true;
		ans.push_back(i);
		if (SZ(bits[i]) > 1)
			toAdd[bits[i][1]] = bits[i][0];
	}
	cout << Mint(2).fastpow(SZ(ans)) << ' ' << SZ(ans) << endl;
	for (auto v : ans)
		cout << 1+v << ' ';
	cout << endl;
}