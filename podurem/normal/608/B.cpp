
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
	string s1, s2;
	cin >> s1 >> s2;
	vector <ll> dp(s1.size());
	dp[0] = 0;
	forn(i, s2.size() - s1.size() + 1)
		dp[0] += (int)(s1[0] != s2[i]);
	for (int i = 1; i < s1.size(); i++)
		if (s1[i] == s1[i - 1])
		{
			dp[i] = dp[i - 1];
			if (s1[i - 1] != s2[i - 1])
				dp[i]--;
			if (s1[i] != s2[s2.size() - s1.size() + i])
				dp[i]++;
		}
		else
		{
			dp[i] = dp[i - 1];
			if (s1[i - 1] != s2[i - 1])
				dp[i]--;
			dp[i] = s2.size() - s1.size() - dp[i];
			if (s1[i] != s2[s2.size() - s1.size() + i])
				dp[i]++;
		}
	ll ans = 0;
	forn(i, s1.size())
		ans += dp[i];
	cout << ans;
	return 0;
}