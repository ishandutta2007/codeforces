#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define for1(i, n) for (int i = 1; i <= (int)n; i++)
#define forq(i, s, t) for (int i = s; i <= (int)t; i++)
#define ford(i, s, t) for (int i = s; i >= (int)t; i--)
#define mk make_pair
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK ""

const double EPS = 1e-15;
const double PI = acos(-1.0);
const int MAXN = (int)1e5 + 7;
const int INF = (int)1e9 + 7;
const int MOD = (int)1e9 + 7;
const ll P = 239017;

int solve();

int main()
{
#ifdef _DEBUG
	//freopen("test.txt", "w", stderr);
	double tstart = TIME;
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	solve();
#ifdef _DEBUG
	double tend = TIME;
	cerr << tend - tstart << " s.\n";
#endif
	return 0;
}

int solve()
{
	//freopen("std.in", "r", stdin);
	//freopen("std.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, x, y;
	bool f = 0;
	cin >> n >> m;
	vector <vi> a(n);
	forn(i, m)
	{
		cin >> x >> y;
		a[x - 1].push_back(y - 1);
		a[y - 1].push_back(x - 1);
		if (x == 1 && y == n || x == n && y == 1)
			f = 1;
	}
	forn(i, n)
		sort(a[i].begin(), a[i].end());
	if (f)
	{
		vector <vi> a1(n);
		forn(i, n)
		{
			int uk = 0;
			forn(j, n)
				if (uk == a[i].size())
					if (j != i) a1[i].push_back(j); else {}
				else
					if (a[i][uk] != j)
						if (i != j) a1[i].push_back(j); else {}
					else
						uk++;
			a[i].resize(0);
			forn(i1, a1[i].size())
				a[i].push_back(a1[i][i1]);
		}
	}
	queue <int> q;
	vector <bool> used(n, 0);
	vector <int> ans(n, -1);
	ans[0] = 0;
	q.push(0);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		used[x] = 1;
		forn(i, a[x].size())
			if (used[a[x][i]] == 0)
			{
				ans[a[x][i]] = ans[x] + 1;
				q.push(a[x][i]);
				used[a[x][i]] = 1;
			}
	}
	cout << ans[n - 1];
	return 0;
}