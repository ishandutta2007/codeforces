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
const int MAXN = (int)1e6 + 7;
const double EPS = (double)1e-7;

int main()
{
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s, s1 = "", c, c1 = "";
	cin >> s >> c;
	bool f = 0;
	forn(i, s.size())
	{
		if (s[i] != '0')
			f = 1;
		if (f)
			s1 += s[i];
	}
	f = 0;
	forn(i, c.size())
	{
		if (c[i] != '0')
			f = 1;
		if (f)
			c1 += c[i];
	}
	if (s1.size() > c1.size())
	{
		cout << ">";
		return 0;
	}
	if (c1.size() > s1.size())
	{
		cout << "<";
		return 0;
	}
	forn(i, s1.size())
	{
		if (s1[i] > c1[i])
		{
			cout << ">";
			return 0;
		}
		if (c1[i] > s1[i])
		{
			cout << "<";
			return 0;
		}
	}
	cout << "=";
	return 0;
}