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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e5 + 10;
string s;
string dpstr[sz], pre[sz];
int dp[sz];


string cropPre(string s) {
	return s.substr(0, min((size_t)4, s.length()));
}

string crop(string s) {
	if (s.length() <= 10)return s;
	string ret = "";
	ret += s.substr(0, 5);
	ret += "...";
	ret += s.substr(s.length() - 2, 2);
	return ret;
}

int main() {
	fast;
	cin >> s;
	int n = s.length();
	dpstr[n] = "";
	pre[n] = "";
	dp[n] = 0;
	dpstr[n - 1] = s.substr(n - 1, 1);
	pre[n - 1] = dpstr[n - 1];
	dp[n - 1] = 1;
	ford(i, n - 2, 0) {
		dpstr[i] = crop(s[i] + dpstr[i + 1]);
		pre[i] = cropPre(s[i] + pre[i + 1]);
		dp[i] = dp[i + 1] + 1;
		if (s[i] == s[i + 1]) {
			if (pre[i].compare(pre[i + 2]) > 0) {
				pre[i] = pre[i + 2];
				dpstr[i] = dpstr[i + 2];
				dp[i] = dp[i + 2];
			}
		}
	}
	foru(i, 0, n) cout << dp[i] << ' ' << dpstr[i] << '\n';
	return 0;
}