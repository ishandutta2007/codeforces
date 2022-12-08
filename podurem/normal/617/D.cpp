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
typedef pair<int, int> pii;
typedef vector<int> vi;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define mk make_pair
#define psh push_back
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK ""

const ll INF = (ll)1e17 + 7;

int main()
{
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if (x1 == x2 && x2 == x3 || y1 == y2 && y2 == y3)
	{
		cout << 1;
		return 0;
	}
	if (x1 == x2 && (y3 >= max(y1, y2) || y3 <= min(y1, y2)) || x3 == x2 && (y1 >= max(y3, y2) || y1 <= min(y3, y2)) || x1 == x3 && (y2 >= max(y1, y3) || y2 <= min(y1, y3)))
	{
		cout << 2;
		return 0;
	}
	if (y1 == y2 && (x3 >= max(x1, x2) || x3 <= min(x1, x2)) || y3 == y2 && (x1 >= max(x3, x2) || x1 <= min(x3, x2)) || y1 == y3 && (x2 >= max(x1, x3) || x2 <= min(x1, x3)))
	{
		cout << 2;
		return 0;
	}
	cout << 3;
	return 0;
}