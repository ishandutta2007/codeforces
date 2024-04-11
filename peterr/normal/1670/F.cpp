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
const int MAXN = 1055;
Mint dp[MAXN];
Mint dptemp[MAXN];
Factorials fac(MAXN);
Mint validWays[61];

Mint solve(int n, long long r, long long z)
{
	validWays[0] = 1;
	for (int i = 1; i <= 60; i++)
	{
		Mint ways = 0;
		for (int j = (z & (1LL << (i - 1))) ? 1 : 0; j <= n; j += 2)
			ways += fac.C(n, j);
		validWays[i] = validWays[i - 1] * ways;
	}
	Mint ans = 0;
	fill(dp, dp + MAXN, 0);
	dp[0] = 1;
	long long prev = 0;
	//long long maxind = 0;
	for (int i = 59; i >= 0; i--)
	{
		long long cur = prev;
		if (r & (1LL << i))
			cur = cur | (1LL << i);
		//cout << "cur " << cur << endl;
		fill(dptemp, dptemp + MAXN, 0);
		for (int j = 0; j < MAXN; j++)
		{
			long long num = prev - j * (1LL << (i + 1));
			if (num < 0)
				break;
			for (int k = 0; k <= MAXN; k++)
			{
				long long newnum = num + k * (1LL << i);
				if (newnum > r)
					break;
				if ((k & 1) != ((z >> i) & 1))
					continue;
				//cout << "newnum " << newnum << endl;
				long long ind = (cur - newnum) / (1LL << i);
				//maxind = max(maxind, ind);
				//cout << "ind " << ind << endl;
				if (ind < MAXN)
					dptemp[ind] += fac.C(n, k) * dp[j];
				else
					ans += fac.C(n, k) * dp[j] * validWays[i];
			}
		}
		swap(dp, dptemp);
		prev = cur;
	}
	for (int i = 0; i < MAXN; i++)
		ans += dp[i];
	//cout << "maxind " << maxind << endl;
	return ans;
}

int main()
{
	int n;
	long long l, r, z;
	cin >> n >> l >> r >> z;
	cout << solve(n, r, z) - solve(n, l - 1, z) << "\n";
	return 0;
}