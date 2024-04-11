#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

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

const int MAXN = 2e5;
struct Path
{
	int parity;
	Mint val;
};

Mint sumPaths[2];
int cntPaths[2];
vector<int> G[MAXN];
bool blocked[MAXN];
int sz[MAXN];
vector<Path> paths;
int szAbove[MAXN];
int par[MAXN];
int val[MAXN];
Mint ans(0);

void initDFS(int u, int p)
{
	sz[u] = 1;
	par[u] = p;
	for (auto v : G[u])
		if (v != p and !blocked[v])
		{
			initDFS(v, u);
			sz[u] += sz[v];
		}
}

int getCentroid(int entryPoint)
{
	int curCentroid = entryPoint;
	int curSize = 1e9;
	szAbove[entryPoint] = 0;

	queue<int> q;
	q.push(entryPoint);
	while (SZ(q))
	{
		int u = q.front(); q.pop();

		int maxSize = szAbove[u];
		for (auto v : G[u])
			if (!blocked[v] and v != par[u])
			{
				szAbove[v] = szAbove[u] + sz[u] - sz[v];
				q.push(v);
				maxSize = max(maxSize, sz[v]);
			}
		if (maxSize < curSize)
		{
			curCentroid = u;
			curSize = maxSize;
		}
	}
	return curCentroid;
}

void runDFS(int u, int p, int lenPath, Mint cumuSum)
{
	cumuSum = val[u] - cumuSum;
	paths.push_back({lenPath%2, cumuSum});

	if (lenPath % 2)
		ans += 2 * cumuSum;

	if (lenPath % 2)
		ans += 2 * (cumuSum * cntPaths[0] + sumPaths[0]);
	else
		ans += 2 * (cumuSum * cntPaths[1] + sumPaths[1]);

	for (auto v : G[u])
		if (!blocked[v] and v != p)
			runDFS(v, u, lenPath+1, cumuSum);
}

void divideAndConquer(int entryPoint)
{
	initDFS(entryPoint, entryPoint);

	int centroid = getCentroid(entryPoint);
	ans += val[centroid];
	sumPaths[0] = sumPaths[1] = 0;
	cntPaths[0] = cntPaths[1] = 0;

	for (auto v : G[centroid])
		if (!blocked[v])
		{
			paths.clear();
			runDFS(v, centroid, 2, val[centroid]);
			for (auto p : paths)
			{
				sumPaths[1 - p.parity] += p.val + (p.parity ? -1 : 1) * val[centroid];
				cntPaths[1-p.parity]++;
			}
		}
	blocked[centroid] = true;
	for (auto v : G[centroid])
		if (!blocked[v])
			divideAndConquer(v);
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbSommets;
	cin >> nbSommets;
	for (int i(0); i < nbSommets; ++i)
		cin >> val[i];
	for (int i(1); i < nbSommets; ++i)
		{
			int _u, _v;
			cin >> _u >> _v;
			--_u, --_v;
			G[_u].push_back(_v);
			G[_v].push_back(_u);
		}

	divideAndConquer(0);
	cout << ans << endl;	
}