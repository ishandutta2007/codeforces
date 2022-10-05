#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

string s;
bool b, dp[5000][5000];
int ans = 0, c[2];

int main() {
	fast;
	cin >> s;
	for (int i = 0; i < s.size(); i++) for (int j = i; j < s.size(); j++) dp[i][j] = true;
	for (int i = 0; i < s.size(); i++) {
		c[0] = c[1] = 0;
		b = true;
		for (int j = i; j < s.size(); j++) {
			if (s[j] == '(') c[0]++;
			else if (s[j] == ')') c[0]--;
			else c[1]++;
			
			if (c[0] < 0) {
				c[0] = 0, c[1]--;
				if (c[1] < 0) b = false;
			}
			if (b && s[j] != '(' && ((j - i) & 1) && c[1] >= c[0]) {
				dp[i][j] = true;
			}
			else dp[i][j] = false;
		}
	}
//	for (int i = 0; i < s.size(); i++) {
//		for (int j = i; j < s.size(); j++) cout << dp[i][j] << " "; cout << endl;
//	}

	for (int i = 0; 2 * i + 1 < s.size(); i++) swap(s[i], s[s.size() - i - 1]);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') s[i] = ')';
		else if (s[i] == ')') s[i] = '(';
	}

	for (int i = 0; i < s.size(); i++) {
		c[0] = c[1] = 0;
		b = true;
		for (int j = i; j < s.size(); j++) {
			if (s[j] == '(') c[0]++;
			else if (s[j] == ')') c[0]--;
			else c[1]++;

			if (c[0] < 0) {
				c[0] = 0, c[1]--;
				if (c[1] < 0) b = false;
			}
//			cout << "i " << i << " j " << j << " c = " << c[0] << " " << c[1] << endl;
			if (b && s[j] != '(' && ((j - i) & 1) && c[1] >= c[0]) {
				dp[s.size() - 1 - j][s.size() - 1 - i] = dp[s.size() - 1 - j][s.size() - 1 - i] && true;
			}
			else dp[s.size() - 1 - j][s.size() - 1 - i] = false;
		}
	}
//	for (int i = 0; i < s.size(); i++) {
//		for (int j = i; j < s.size(); j++) cout << dp[i][j] << " "; cout << endl;
//	}
	for (int i = 0; i < s.size(); i++) for (int j = i; j < s.size(); j++) if (dp[i][j]) ans++;
	cout << ans << endl;
}