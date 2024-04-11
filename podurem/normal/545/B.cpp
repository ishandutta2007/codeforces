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
	string s, t, p;
	cin >> s >> t;
	vi a;
	forn(i, s.size())
		if (s[i] != t[i])
			a.psh(i);
	if (a.size() % 2)
	{
		cout << "impossible";
		return 0;
	}
	p = s;
	forn(i, a.size())
		if (i % 2)
			p[a[i]] = s[a[i]];
		else
			p[a[i]] = t[a[i]];
	cout << p;
	return 0;
}