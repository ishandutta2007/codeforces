
#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXMASK = (1<<20);

struct Path
{
	int endVertice;
	int mask;
};

const int MAXN = 2e5;
vector<int> G[MAXN];
int sz[MAXN], par[MAXN], szAbove[MAXN];
bool blocked[MAXN];
int cnt[MAXMASK];
ll sol[MAXN];
ll tempSolCross[MAXN], tempSolStraight[MAXN];
int mask[MAXN];

void initDFS(int u, int p)
{
	par[u] = p;
	sz[u] = 1;
	tempSolCross[u] = tempSolStraight[u] = 0;
	for (auto v : G[u])
		if (!blocked[v] and par[u] != v)
		{
			initDFS(v, u);
			sz[u] += sz[v];
		}
}

int getCentroid(int entryPoint)
{
	int curCentroid = entryPoint;
	int curSize = 1e9;
	queue<int> q;
	q.push(entryPoint);
	szAbove[entryPoint] = 0;
	while (SZ(q))
	{
		int u = q.front(); q.pop();

		int maxSize = szAbove[u];
		for (auto v : G[u])
			if (!blocked[v] and v != par[u])
			{
				q.push(v);
				szAbove[v] = szAbove[u] + sz[u] - sz[v];
				maxSize = max(maxSize, sz[v]);
			}
		if (maxSize < curSize)
			curCentroid = u, curSize = maxSize;
	}
	return curCentroid;
}

void getAllPaths(int u, int p, int curMask, vector<Path> &paths)
{
	curMask ^= mask[u];
	paths.push_back({u, curMask});
	for (auto v : G[u])
		if (!blocked[v] and v != p)
			getAllPaths(v, u, curMask, paths);
}

void aggregatePaths(int u, int p)
{
	for (auto v : G[u])
		if (v != p and !blocked[v])
		{
			aggregatePaths(v, u);
			tempSolStraight[u] += tempSolStraight[v];
			tempSolCross[u] += tempSolCross[v];
		}
	sol[u] += tempSolCross[u] + tempSolStraight[u];;
}

void divideAndConquer(int entryPoint)
{
	initDFS(entryPoint, entryPoint);
	int centroid = getCentroid(entryPoint);

	vector<vector<Path>> allPaths;

	for (auto v : G[centroid])
		if (!blocked[v])
		{
			vector<Path> paths;
			getAllPaths(v, centroid, mask[centroid], paths);
			allPaths.push_back(paths);
		}

	for (auto v : allPaths)
		for (auto w : v)
			cnt[w.mask]++;

	for (auto v : allPaths)
	{
		for (auto w : v)
			cnt[w.mask]--;

		for (auto w : v)
		{
			if (__builtin_popcount(w.mask) <= 1)
				tempSolStraight[w.endVertice]++;
			tempSolCross[w.endVertice] += cnt[w.mask^mask[centroid]];
			for (int i(0); i < 20; ++i)
				tempSolCross[w.endVertice] += cnt[w.mask ^ (1<<i) ^ mask[centroid] ];
		}

		for (auto w : v)
			cnt[w.mask]++;
	}

	aggregatePaths(centroid, centroid);
	sol[centroid] -= tempSolCross[centroid]/2;
	sol[centroid]++;

	for (auto v : allPaths)
		for (auto w : v)
			cnt[w.mask] = 0;

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

	for (int i(1); i < nbSommets; ++i)
		{
			int _u, _v;
			cin >> _u >> _v;
			--_u, --_v;
			G[_u].push_back(_v);
			G[_v].push_back(_u);
		}

	string s;
	cin >> s;
	for (int i(0); i < nbSommets; ++i)
		mask[i]	= (1<< (s[i] - 'a'));

	divideAndConquer(0);
	for (int i(0); i < nbSommets; ++i)
		cout << sol[i] << ' ';
	cout << endl;
}