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

const int MAXN = 2E5;
Factorials fac(MAXN + 1);
int sz[MAXN + 1];
vector<int> adjList[MAXN + 1];
Mint numRooted[MAXN + 1];
Mint numRootedSum[MAXN + 1];
Mint f[MAXN + 1];
Mint fSum[MAXN + 1];
Mint ans = 0;

void reroot(int x, int y, int k)
{
	sz[x] -= sz[y];
	sz[y] += sz[x];
	
	numRootedSum[x] -= numRootedSum[y] + numRooted[x];
	numRooted[x] = fac.C(sz[x], k) - numRootedSum[x];
	numRootedSum[x] += numRooted[x];
	fSum[x] -= fSum[y] + f[x];
	f[x] = numRooted[x] * sz[x];
	fSum[x] += f[x];
	
	numRootedSum[y] += numRootedSum[x] - numRooted[y];
	numRooted[y] = fac.C(sz[y], k) - numRootedSum[y];
	numRootedSum[y] += numRooted[y];
	fSum[y] += fSum[x] - f[y];
	f[y] = sz[y] * numRooted[y];
	fSum[y] += f[y];
}

void dfs(int v, int p, int k)
{
	//cout << "dfs " << v << " " << sz[v] << " " << f[v] << endl;
	ans += fSum[v];
	for (int adj : adjList[v])
	{
		if (adj == p)
			continue;
		reroot(v, adj, k);
		dfs(adj, v, k);
		reroot(adj, v, k);
	}
}

void precompute(int v, int p, int k)
{
	sz[v] = 1;
	for (int adj : adjList[v])
	{
		if (adj == p)	
			continue;
		precompute(adj, v, k);
		sz[v] += sz[adj];
		numRootedSum[v] += numRootedSum[adj];
		fSum[v] += fSum[adj];
	}
	numRooted[v] = fac.C(sz[v], k) - numRootedSum[v];
	numRootedSum[v] += numRooted[v];
	f[v] = sz[v] * numRooted[v];
	fSum[v] += f[v];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout << fac.C(5, 2) << endl;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	precompute(1, 1, k);
	dfs(1, 1, k);
	cout << ans << "\n";
	return 0;
}