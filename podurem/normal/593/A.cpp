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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
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

bool pod(string s)
{
	set <char> ss;
	for (int i = 0; i < s.size(); i++)
		ss.insert(s[i]);
	return ss.size() <= 2;
}

int solve()
{
	int n;
	cin >> n;
	vector <string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0, kol;
	vector <char> a1;
	for (char a11 = 'a'; a11 <= 'y'; a11++)
		for (char b = a11 + 1; b <= 'z'; b++)
		{
			kol = 0;
			for (int i = 0; i < n; i++)
			{
				if (pod(a[i]))
				{
					a1.clear();
					for (int j = 0; j < a[i].size(); j++)
					{
						if (a1.size() == 0)
							a1.push_back(a[i][j]);
						else
							if (a1[0] != a[i][j])
								a1.push_back(a[i][j]);
						if (a1.size() == 2)
							break;
					}
					if (a1.size() == 1 && (a1[0] == a11 || a1[0] == b))
						kol += a[i].size();
					else
						if (a1.size() == 2)
							if ((a1[0] == a11 && a1[1] == b) || (a1[0] == b && a1[1] == a11))
								kol += a[i].size();
					ans = max(ans, kol);
				}
			}
		}
	cout << ans;
	return 0;
}