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

struct Segtree_add
{
	vector<Mint> seg;
	int p, deb;

	Segtree_add() {}

	Segtree_add(int nb_elem) 
	{
		p = 0;
		while ((1<<p) < nb_elem) ++p;
		deb = (1<<p)-1;
		seg.resize(2*(1<<p));
		for (auto &v : seg) v = 0;
	}

	void update(int pos, Mint x)
	{
		pos += deb;
		seg[pos] = x;
		while (pos)
		{
			pos = (pos-1)/2;
			seg[pos] = seg[2*pos+1] + seg[2*pos+2];
		}
	}

	Mint query(int lo, int up)
	{
		lo += deb;
		up += deb;
		Mint ans = 0;
		while (lo < up)
		{
			if (lo%2==0)
				ans += seg[lo];
			if (up%2)
				ans += seg[up];
			lo /= 2;
			up = (up-2)/2;
		}
		if (lo==up)
			ans += seg[lo];
		return ans;
	}
};

const int MAXP = 30;

int longueur, nb_bits, nb_conditions;
vector<tuple<int, int, int> > conditions;

Mint solve(int p)
{
	vector<Mint> dp(longueur+1);
	int bit = (1<<p);
	vector<int> prefix1(longueur+1);
	vector<int> lst(longueur+2);

	for (auto [l, r, x] : conditions)
		if (bit&x)
		{
			prefix1[l]++;
			if (r+1 <= longueur)
				prefix1[r+1]--;
		}
	for (int i(1); i <= longueur; ++i)
		prefix1[i] += prefix1[i-1];
	for (int i(1); i <= longueur; ++i)
		prefix1[i] = !!prefix1[i];
	for (auto [l, r, x] : conditions)
		if (!(bit&x))
			lst[r+1] = max(lst[r+1], l);
	for (int i(1); i <= longueur+1; ++i)
		lst[i] = max(lst[i], lst[i-1]);

	Segtree_add seg = Segtree_add(longueur+1);
	seg.update(0,1);

	Mint sol(0);
	Mint cumu(0);
	for (int i(1); i <= longueur; ++i)
	{
		if (prefix1[i])
			continue;
		seg.update(i, seg.query(lst[i], i-1));
	}
	sol = seg.query(lst[longueur+1], longueur);	
	return sol;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> longueur >> nb_bits >> nb_conditions;

	conditions.resize(nb_conditions);
	for (auto &[l, r, x] : conditions)
		cin >> l >> r >> x;	
	Mint sol = Mint(1);
	for (int p(0); p < nb_bits; ++p)
		sol *= solve(p);
	cout << sol << endl;
}