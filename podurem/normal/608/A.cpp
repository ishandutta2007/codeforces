
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

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mk make_pair
#define psh push_back
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK ""

const int INF = (int)1e9 + 7;

int main()
{
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, s, x, y;
	cin >> n >> s;
	vi a(s + 1, 0);
	forn(i, n)
	{
		cin >> x >> y;
		a[x] = max(a[x], y);
	}
	int ans = -1;
	for (int i = s; i >= 0; i--)
		ans = max(ans + 1, a[i]);
	cout << ans;
	return 0;
}