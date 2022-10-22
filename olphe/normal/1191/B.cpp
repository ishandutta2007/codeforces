#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"

using namespace std;

//const long long int MOD = 1000000007;
const int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;
const double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t, u;
	cin >> s >> t >> u;
	int ans = 2;
	if (s == t && t == u)ans = min(ans, 0);
	if (s == t || s == u || t == u)ans = min(ans, 1);
	if (s > t)swap(s, t);
	if (t > u)swap(t, u);
	if (s > t)swap(s, t);
	//cout << s << " " << t << " " << u << endl;
	if (s[1] == t[1] && s[0] + 1 == t[0] && t[1] == u[1] && t[0] + 1 == u[0])ans = min(ans, 0);
	if (s[1] == t[1] && s[0] + 1 == t[0])ans = min(ans, 1);
	if (s[1] == t[1] && s[0] + 2 == t[0])ans = min(ans, 1);
	if (t[1] == u[1] && t[0] + 1 == u[0])ans = min(ans, 1);
	if (t[1] == u[1] && t[0] + 2 == u[0])ans = min(ans, 1);
	if (s[1] == u[1] && s[0] + 1 == u[0])ans = min(ans, 1);
	if (s[1] == u[1] && s[0] + 2 == u[0])ans = min(ans, 1);
	cout << ans << endl;
}