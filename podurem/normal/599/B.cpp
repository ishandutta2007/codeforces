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

bool pov[100001];

int solve()
{
	//freopen("name.in", "r", stdin);
	//freopen("name.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int nf, nb, n;
	cin >> nf >> nb;
	vi f(nf), b(nb);
	set <int> sf, sb;
	multiset <int> sf1, sb1;
	set <pii> sf3;
	forn(i, nf)
	{
		cin >> f[i];
		n = sf.size();
		sf.insert(f[i]);
		sf1.insert(f[i]);
		sf3.insert({ f[i], i + 1 });
		if (sf.size() == n)
			pov[f[i]] = 1;
	}
	bool ff = 0;
	forn(i, nb)
	{
		cin >> b[i];
		if (pov[b[i]] == 1)
			ff = 1;
		sb.insert(b[i]);
		sb1.insert(b[i]);
	}
	if (sb.size() > sf.size())
		cout << "Impossible";
	else
	{
		for (set <int>::iterator it = sb.begin(); it != sb.end(); it++)
			if (sf.find(*it) == sf.end())
			{
				cout << "Impossible";
				return 0;
			}
		if (ff)
		{
			cout << "Ambiguity";
			return 0;
		}
		cout << "Possible\n";
		forn(i, nb)
			cout << (*sf3.upper_bound({ b[i], 0 })).second << " ";
	}
	return 0;
}