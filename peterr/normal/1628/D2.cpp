#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
template <int M = MOD>
struct ModularInt 
{
	int val;
	ModularInt(): val(0) {};
	ModularInt(int val_): val(val_ % M) { if (val < 0) val += M; }

	ModularInt pow(long long exp) const
	{
		ModularInt res = 1;
		ModularInt base = val;
		while (exp)
		{
			if (exp & 1)
				res *= base;
			exp >>= 1;
			base *= base;
		}
		return res;
	}
	ModularInt inv() const
	{
		return pow(M - 2);
	}
	friend ModularInt operator*(ModularInt const& mint1, ModularInt const& mint2) { return (int) ((long long) mint1.val * mint2.val % M); }
	friend ModularInt operator+(ModularInt const& mint1, ModularInt const& mint2) { return mint1.val + mint2.val; }
	friend ModularInt operator-(ModularInt const& mint1, ModularInt const& mint2) { return mint1.val - mint2.val; }
	ModularInt& operator++()
	{
		val++;
		if (val == M)
			val = 0;
		return *this;
	}
	ModularInt operator++(int)
	{
		ModularInt temp = *this;
		val++;
		if (val == M)
			val = 0;
		return temp;
	}
	ModularInt& operator--()
	{
		val--;
		if (val == -1)
			val = M - 1;
		return *this;
	}
	ModularInt operator--(int)
	{
		ModularInt temp = *this;
		val--;
		if (val == -1)
			val = M - 1;
		return temp;
	}
	ModularInt& operator+=(ModularInt const& otherMint)
	{
		val += otherMint.val;
		if (val >= M)
			val -= M;
		return *this;
	}
	ModularInt& operator-=(ModularInt const& otherMint)
	{
		val += M - otherMint.val;
		if (val >= M)
			val -= M;
		return *this;
	}
	ModularInt& operator*=(ModularInt const& otherMint)
	{
		val = (int) ((long long) val * otherMint.val % M);
		return *this;
	}
	ModularInt& operator>>=(ModularInt const& otherMint)
	{
		val >>= otherMint.val;
		return *this;
	}
	explicit operator int() const { return val; }
	explicit operator bool() const { return val; }
	friend ostream& operator<<(ostream& out, ModularInt const& mint) { return out << mint.val; }
	friend istream& operator>>(istream& in, ModularInt& mint) { return in >> mint.val; }
};

template <int M = MOD>
struct Factorials
{
	using Mint = ModularInt<M>;
	vector<Mint> f;
	vector<Mint> fi;
	
	Factorials(int n)
	{
		f = vector<Mint>(n + 1);
		fi = vector<Mint>(n + 1);
		f[0] = 1;
		for (int i = 1; i <= n; i++)
			f[i] = f[i - 1] * i;
		fi[n] = f[n].inv();
		for (int i = n; i; i--)
			fi[i - 1] = fi[i] * i;
	}
	
	Mint C(int n, int k)
	{
		if (k < 0 || k > n)
			return 0;
		return f[n] * fi[k] * fi[n - k];
	}
};

using Mint = ModularInt<>;

const int MAXN = 1E6;
Factorials fac(MAXN);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		if (n == m)
		{
			cout << k * Mint(m) << "\n";
			continue;
		}
		Mint ans = 0;
		for (int i = 1; i <= m; i++)
		{
			ans += fac.C(n - i - 1, m - i) * i * Mint(2).pow(n - i).inv();
		}
		cout << ans * k << "\n";
	}
	return 0;
}