//sobskdrbhvk
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const int maxn = 1e6;
int dp[maxn],
	pd[maxn],
	n;
string s;

int main() {
	cin >> n;
	cin >> s;
	int gcnt = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == 'G')
			gcnt++;
	for (int i = 1; i < n; i++) {
		if (s[i - 1] == 'S')
			dp[i] = 0;
		else
			dp[i] = dp[i - 1] + 1;
	}
	for (int i = n - 2; i >= 0; i--) {
		if (s[i + 1] == 'S')
			pd[i] = 0;
		else
			pd[i] = pd[i + 1] + 1;
	}
	
	int ans = (gcnt == n ? n : 0);
	for (int i = 0; i < n; i++)
		if (s[i] == 'S') {
			if (dp[i] + pd[i] == gcnt) {
				smax(ans, dp[i] + pd[i]);
			}
			else {
				smax(ans, dp[i] + pd[i] + 1);
			}
		}
	cout << ans << endl;


	return 0;
}