
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
typedef pair<ll, ll> pll;
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
	int n;
	cin >> n;
	vector <pii> a(n);
	forn(i, n)
		cin >> a[i].first >> a[i].second;
	sort(all(a));
	vector <int> dp(n);
	dp[0] = 0;
	for (int i = 1; i < n; i++)
	{
		int it = lower_bound(all(a), mk(a[i].first - a[i].second, 0)) - a.begin();
		dp[i] = i - it;
		//cout << it << " ";
		if (it != 0)
			dp[i] += dp[it - 1];
		//cout << dp[i] << "\n";
	}
	int ans = 2 * n;
	forn(i, n)
		ans = min(ans, dp[i] + n - i - 1);
	cout << ans;
	return 0;
}