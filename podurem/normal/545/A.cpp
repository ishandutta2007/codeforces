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

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef set <ll> sll;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forq(i, q, n) for (int i = (int)q; i < (int)n; ++i)
#define forb(i, n, q) for (int i = (int)n; i >= (int)q; ++i)
#define fornll(i, n) for (ll i = 0; i < (ll)n; ++i)
#define forqll(i, q, n) for (ll i = (ll)q; i < (ll)n; ++i)
#define forbll(i, n, q) for (ll i = (ll)n; i >= (ll)q; ++i)
#define mk make_pair
#define psh push_back
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK ""

const int INF = (int)1e9 + 7;
const int MOD = (int)1e9 + 7;
const double EPS = (double)1e-8;

int main()
{
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector <vi> a(n, vi(n));
	forn(i, n)
		forn(j, n)
			cin >> a[i][j];
	vi ans;
	bool f;
	forn(i, n)
	{
		f = 1;
		forn(j, n)
			if (a[i][j] == 1 || a[i][j] == 3)
				f = 0;
		if (f)
			ans.psh(i + 1);
	}
	cout << ans.size() << "\n";
	forn(i, ans.size())
		cout << ans[i] << " ";
	return 0;
}