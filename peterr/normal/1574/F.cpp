#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 6E5;
const int BLOCK = 550;
int par[MAXN];
int sz[MAXN];
vector<int> a[MAXN];
vector<int> who_[MAXN];
bool isBad[MAXN];
vector<int> objects;
int dp[MAXN + 1];
int freq[BLOCK];
vector<int> adjList[MAXN];
int inDeg[MAXN];
int outDeg[MAXN];

int getRoot(int x)
{
	if (par[x] != x)
		par[x] = getRoot(par[x]);
	return par[x];
}

bool mge(int x, int y)
{
	x = getRoot(x);
	y = getRoot(y);
	if (x == y)
		return false;
	if (sz[x] < sz[y])
		swap(x, y);
	par[y] = x;
	sz[x] += sz[y];
	for (int z : who_[y])
		who_[x].push_back(z);
	return true;
}

void add(int &x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int solve(int n)
{
	vector<int> big;
	for (int num : objects)
	{
		if (num >= BLOCK)
			big.push_back(num);
		else
			freq[num]++;
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int b : big)
			if (i - b >= 0)
				add(dp[i], dp[i - b]);
		for (int j = 1; j < BLOCK; j++)
			if (i - j >= 0)
				add(dp[i], (int) ((long long) freq[j] * dp[i - j] % MOD));
	}
	return dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < MAXN; i++)
	{
		par[i] = i;
		sz[i] = 1;
	}
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		a[i] = vector<int>(c);
		set<int> seen;
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
			a[i][j]--;
			if (seen.count(a[i][j]))
				isBad[i] = true;
			seen.insert(a[i][j]);
			if (j)
			{
				adjList[a[i][j - 1]].push_back(a[i][j]);
				outDeg[a[i][j - 1]]++;
				inDeg[a[i][j]]++;
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		a[n + i] = {i};
	}
	n += k;
	for (int i = 0; i < n; i++)
	{
		int num = a[i][0];
		who_[getRoot(num)].push_back(i);
		for (int j : a[i])
		{
			mge(j, num);
		}
	}
	for (int i = 0; i < k; i++)
	{
		if (getRoot(i) != i)
			continue;
		int r = getRoot(i);
		bool valid = true;
		set<int> nums;
		for (int ind : who_[r])
		{
			if (isBad[ind])
				valid = false;
			for (int x : a[ind])
				nums.insert(x);
		}
		if (!valid)
			continue;
		int sources = 0;
		int sinks = 0;
		for (int x : nums)
		{
			if (!inDeg[x])
				sources++;
			if (!outDeg[x])
				sinks++;
			if (outDeg[x])
			{
				for (int y : adjList[x])
					if (y != adjList[x].back())
						valid = false;
			}
		}
		if (sources != 1 || sinks != 1)
			valid = false;
		if (!valid)
			continue;
		//cout << "pushing " << i << endl;
		//cout << "sz " << sz[r] << endl;
		objects.push_back(sz[r]);
	}
	int ans = solve(m);
	cout << ans << "\n";
	return 0;
}