#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <unordered_set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef long double ld;
typedef pair <ld, ld> pld;

const int sz = 2e5;
int n, k, nxt[sz + 1];
bitset<sz + 1> bs;
ll dp[sz + 1];

int main() {
	fast;
	string s;
	cin >> n >> k >> s;
	for (int i = 1; i <= n; i++) bs[i] = (s[i - 1] == '1');
	int prv = -1;
	for (int i = n; i >= 1; i--) {
		if (bs[i])prv = i;
		nxt[i] = prv;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		while (!q.empty() && i > q.front() + k)q.pop();
		if (bs[i])q.push(i);
		if (q.empty())dp[i] = i + dp[i - 1];
		else {
			int ind = max(q.front() - k - 1, 0);
			dp[i] = q.front() + dp[ind];
			if (ind == 0)continue;
			int mynxt = nxt[ind];
			if (mynxt != -1) {
				if (mynxt - ind <= k)
					dp[i] = min(dp[i], q.front() + mynxt + dp[(max(mynxt - k - 1, 0))]);
			}
		}
	}
	cout << dp[n] << '\n';
	return 0;
}