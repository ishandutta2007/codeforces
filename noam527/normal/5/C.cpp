#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

string s;
int mx = 0, c = 1;

int main() {
	fast;
	cin >> s;
	vector<int> dp(s.size(), 0);
	dp[0] = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == ')') {
			if (s[i - 1] == '(') {
				dp[i] = 2;
				if (i != 1) dp[i] += dp[i - 2];
			}
			if (i - dp[i - 1] > 0) {
				if (s[i - dp[i - 1] - 1] == '(') {
					if (i - dp[i - 1] - 1 > 0) dp[i] = max(dp[i], 2 + dp[i - 1] + dp[i - dp[i - 1] - 2]);
					else dp[i] = max(dp[i], 2 + dp[i - 1]);
				}
			}
		}
	}
	for (auto &i : dp) {
		if (i == mx) c++;
		else if (i > mx) mx = i, c = 1;
	}
	if (mx == 0) c = 1;
	cout << mx << " " << c << endl;
}