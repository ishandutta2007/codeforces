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

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define mk make_pair
#define psh push_back
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK ""

const int INF = (int)1e9 + 7;
const int MAXN = (int)1e3 + 7;
const double EPS = (double)1e-7;

int main()
{
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a1 = 0, a2 = -1;
	int n, k;
	cin >> n >> k;
	vi v(n);
	forn(i, n)
		scanf("%d", &v[i]);
	int uk1 = 0, uk2 = 1;
	multiset <int> a;
	set <int> s;
	a.insert(v[0]);
	s.insert(v[0]);
	while (uk2 != n)
	{
		//cout << uk1 << " " << uk2 << "\n";
		if (s.size() <= k)
		{
			if (a2 - a1 < uk2 - uk1)
			{
				a1 = uk1;
				a2 = uk2;
			}
			a.insert(v[uk2]);
			s.insert(v[uk2]);
			uk2++;
		}
		else
		{
			a.erase(a.find(v[uk1]));
			if (a.find(v[uk1]) == a.end())
				s.erase(v[uk1]);
			uk1++;
		}
	}
	if (s.size() > k)
		while (s.size() > k)
		{
			a.erase(a.find(v[uk1]));
			if (a.find(v[uk1]) == a.end())
				s.erase(v[uk1]);
			uk1++;
		}
	if (a2 - a1 < uk2 - uk1)
	{
		a1 = uk1;
		a2 = uk2;
	}
	cout << a1 + 1 << " " << a2;
	return 0;
}