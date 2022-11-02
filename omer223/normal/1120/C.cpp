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
#include <list>
#include <bitset>
#include <queue>
#include <map>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int n, a, b;
const int sz = 5e3;
string s;
bool is[sz][sz];
int Z[2 * sz + 1];
ll dp[sz];

int calcZ(string pat, string text, int i) {
	string str = pat + '#' + text;
	int zLen = str.length();
	int L, R, k;
	L = R = 0;
	for (int i = 1; i < zLen; ++i){
		if (i > R){
			L = R = i;
			while (R < zLen && str[R - L] == str[R])R++;
			Z[i] = R - L;
			R--;
		}
		else {
			k = i - L;
			if (Z[k] < R - i + 1)Z[i] = Z[k];
			else {
				L = i;
				while (R < zLen && str[R - L] == str[R])R++;
				Z[i] = R - L;
				R--;
			}
		}
	}
	int ans = 0;
	for (int j = pat.length()+1; j < zLen; j++) {
		int ind = j - pat.length()-1, actualZ = min(Z[j], i - ind);
		ans = max(ans, actualZ);
	}
	return ans;
}

void initIs() {
	foru(i, 0, n) {
		int mxZ = calcZ(s.substr(i, n - i), s, i);
		foru(j, i, i + mxZ)is[i][j] = 1;
	}
}

int main() {
	fast;
	cin >> n >> a >> b >> s;
	n = s.length();
	initIs();
	dp[0] = a;
	foru(i, 1, n) {
		dp[i] = a + dp[i - 1];
		ford(j, i, 1) { 
			if (is[j][i])
				dp[i] = min(dp[i], dp[j - 1] + b);
		}
	}
	cout << dp[n - 1] << endl;
	return 0;
}