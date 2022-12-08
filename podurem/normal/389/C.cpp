
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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mk make_pair
#define psh push_back
#define X first
#define Y second
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK ""

const int INF = (int)1e9 + 7;
const int MAXN = (int)1e5 + 7;
const double EPS = (double)1e-8;

int main()
{
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x;
	cin >> n;
	multiset <int> a;
	forn(i, n)
	{
		cin >> x;
		a.insert(x);
	}
	int kol = 0, s;
	set <int>::iterator it, it1;
	while (a.size() != 0)
	{
		++kol;
		s = 1;
		it = a.begin();
		while (it != a.end())
		{
			a.erase(it);
			it = lower_bound(all(a), s);
			++s;
		}
	}
	cout << kol;
	return 0;
}