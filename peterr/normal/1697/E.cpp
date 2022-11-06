#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
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
	
	Mint P(int n, int k)
	{
		if (k < 0 || k > n)
			return 0;
		return f[n] * fi[n - k];
	}
};

using Mint = ModularInt<>;
const int MAXN = 100;
pair<int, int> a[MAXN];
int d[MAXN][MAXN];
vector<int> nxt[MAXN];
Mint ways[MAXN + 1][MAXN + 1];
bool visited[MAXN];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0; i < n; i++)
	{
		int mind = 1E9;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			d[i][j] = abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
			if (d[i][j] < mind)
			{
				nxt[i].clear();
				nxt[i].push_back(j);
				mind = d[i][j];
			}
			else if (d[i][j] == mind)
			{
				nxt[i].push_back(j);
			}
		}
		if (nxt[i].size() > 3)
			nxt[i].clear();
		//cout << "nxt " << i << " ";
		//for (int x : nxt[i])
			//cout << x << " ";
		//cout << endl;
	}
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		if (visited[i])
			continue;
		if (nxt[i].empty())
			vec.push_back(1);
		else if (nxt[i].size() == 1)
		{
			int adj = nxt[i][0];
			if (nxt[adj].size() == 1 && nxt[adj][0] == i)
			{
				vec.push_back(2);
				visited[adj] = true;
			}
			else
				vec.push_back(1);
		}
		else if (nxt[i].size() == 2)
		{
			//cout << "HERE\n";
			int adj1 = nxt[i][0];
			int adj2 = nxt[i][1];
			if (nxt[adj1].size() == 2
				&& nxt[adj2].size() == 2
				&& (
					(nxt[adj1][0] == i && nxt[adj1][1] == adj2 || nxt[adj1][0] == adj2 && nxt[adj1][1] == i)
					&& (nxt[adj2][0] == i && nxt[adj2][1] == adj1 || nxt[adj2][0] == adj1 && nxt[adj2][1] == i)
				))
			{
				vec.push_back(3);
				visited[adj1] = visited[adj2] = true;
			}
			else
				vec.push_back(1);
		}
		else if (nxt[i].size() == 3)
		{
			bool valid = true;
			for (int j : nxt[i])
			{
				if (nxt[j].size() != 3)
					valid = false;
			}
			if (valid)
			{
				vector<int> good = {i, nxt[i][0], nxt[i][1], nxt[i][2]};
				for (int j : nxt[i])
				{
					for (int k : nxt[j])
					{
						if (k != i && k != nxt[i][0] && k != nxt[i][1] && k != nxt[i][2])
							valid = false;
					}
				}
				if (valid)
				{
					vec.push_back(4);
					for (int j : nxt[i])
						visited[j] = true;
				}
				else
					vec.push_back(1);
			}
			else
				vec.push_back(1);
		}
		visited[i] = true;
	}
	//cout << "vec ";
	//for (int x : vec)
		//cout << x << " ";
	//cout << endl;
	ways[0][0] = 1;
	for (int i = 0; i < (int) vec.size(); i++)
	{
		for (int j = 0; j <= MAXN; j++)
		{
			if (!ways[i][j])
				continue;
			ways[i + 1][j + vec[i]] += ways[i][j];
			if (vec[i] > 1)
				ways[i + 1][j + 1] += ways[i][j];
		}
	}
	Mint ans = 0;
	Factorials fac(MAXN);
	for (int i = 1; i <= MAXN; i++)
	{
		ans += ways[(int) vec.size()][i] * fac.P(n, i);
	}
	cout << ans << "\n";
	return 0;
}