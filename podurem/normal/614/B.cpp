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
#define TASK "exam"

const int INF = (int)1e9 + 7;
const int MAXN = (int)1e5 + 7;
const double EPS = (double)1e-8;

int main()
{
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, kol = 0;
	cin >> n;
	string s, c = "1", s1;
	bool f;
	while (n--)
	{
		cin >> s;
		if (s[0] == '0')
		{
			cout << 0;
			return 0;
		}
		if (s[0] != '1')
		{
			c = s;
			continue;
		}
		f = 1;
		int kol1 = 0;
		for (int i = 1; i < s.size(); ++i)
			if (s[i] != '0')
			{
				c = s;
				f = 0;
				break;
			}
			else
				++kol1;
		if (f)
			kol += kol1;
	}
	cout << c;
	forn(i, kol)
		printf("0");
	return 0;
}