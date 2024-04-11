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
	int n;
	ll x1, y1, x2, y2, x, y;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	vector <ll> r1(n), r22(n);
	forn(i, n)
	{
		cin >> x >> y;
		r1[i] = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
		r22[i] = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
	}
	ll ans = INF, r2;
	vector <char> used(n);
	r2 = 0;
	used.assign(n, 0);
	forn(j, n)
		if (used[j] == 0 && r22[j] > r2)
			r2 = r22[j];
	ans = min(ans, r2);
	forn(i, n)
	{
		r2 = 0;
		used.assign(n, 0);
		forn(j, n)
			if (r1[j] <= r1[i])
				used[j] = 1;
		forn(j, n)
			if (used[j] == 0 && r22[j] > r2)
				r2 = r22[j];
		ans = min(ans, r1[i] + r2);
	}
	cout << ans;
	return 0;
}