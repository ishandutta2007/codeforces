#define MOD 998244353
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define has(set, x) set.find(x) != set.end()
#define nohas(set, x) set.find(x) == set.end()
#define inc(mpp, x) {if(has(mpp, x)) mpp[x]++; else mpp.insert(mp(x,1));}
#define decc(mpp, x) {if(has(mpp, x)) {if(mpp[x] > 1) mpp[x]--; else mpp.erase(x);}}
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define um unordered_map
#define us unordered_set
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <stack>
#include <deque>
#include <queue>
#include <bitset>
#include <numeric>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }
const int sz = 200;
bool block[sz];
ll dp[sz][2];
string parseStr(string s) {
	string ans = "";
	int n = s.length(), pre = 0, suf = 0;
	foru(i, 0, n) {
		if (s[i] == s[0])pre++;
		else break;
	}
	ford(i, n - 1, 0) {
		if (s[i] == s[n - 1])suf++;
		else break;
	}
	if (s[0] == s[n - 1]) {
		ans.pb(s[0]);
		ans.pb(s[0]);
	}
	else {
		pre = 0, suf = 0;
	}
	if (pre == n)return ans;
	char prev;
	bool vis = false;
	int cnt = 1;
	for (int i = pre; i < n - suf; i++) {
		if (vis) {
			if (s[i] == s[i - 1])cnt++;
			else {
				if (cnt >= 2)ans.pb(s[i - 1]);
				ans.pb(s[i - 1]);
				cnt = 1;
			}
		}
		vis = 1;
	}
	if (cnt >= 2)ans.pb(s[n - suf - 1]);
	ans.pb(s[n - suf - 1]);
	return ans;
}

vi getVec(string s) {
	vi ans;
	int cnt = 0,n=s.length();
	foru(i, 0, n) {
		if (!i || s[i] == s[i - 1])cnt++;
		else {
			ans.pb(cnt);
			cnt = 1;
		}
	}
	ans.pb(cnt);
	return ans;
}

bool checkBad(string sr) {
	vector<int> v = getVec(sr);
	int vlen = v.size();
	bool startsWithA = (sr[0] == 'A'), bad = false;
	foru(i, 0, vlen) {
		if (startsWithA ^ (i & 1)) { //A
			if (v[i] == 2 && v[(i + 1) % vlen] == 2) {
				bad = true;
				break;
			}
		}
	}
	return bad;
}
void preCalc() {
	dp[0][0] = 1;//a
	dp[0][1] = 1;//b
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[2][0] = 0;
	dp[2][1] = 2;
	dp[3][0] = 1;
	dp[3][1] = 1;
	foru(i, 4, sz) {
		dp[i][0] = dp[i - 3][1];
		dp[i][1] = dp[i - 2][1] + dp[i - 4][1];
	}
}
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	string s;
	cin >> s;
	string sr = parseStr(s);
	if (sr.length() == 2) {
		cout << 1 << endl;
		return 0;
	}
	if (checkBad(sr)) {
		cout << 0 << endl;
		return 0;
	}
	int len = sr.length(), blockex;
	foru(i, 0, len) {
		if (i&&sr[i] == sr[i - 1]) {
			if (sr[i] == 'A') {
				block[i] = 1;
				block[(i + 1) % len] = 1;
				block[(i + 2) % len] = 1;
				blockex = i;
			}
			else {
				block[(i - 1 + len) % len] = 1;
				block[(i - 2 + len) % len] = 1;
				block[(i - 3 + len) % len] = 1;
				blockex = i - 1;
			}
		}
	}
	int pre = 0, suf = 0;
	foru(i, 0, len) {
		if (!i||sr[i] != sr[i - 1])pre++;
		else break;
	}
	ford(i, len - 1, 0) {
		if (i==len-1||sr[i] != sr[i + 1])suf++;
		else break;
	}
	preCalc();
	if (pre == len) {
		cout << dp[len - 2][1] + dp[len - 3][1] << endl;
	}
	else {
		ll ans = 1;
		int cnt = 0;
		bool startWithA = false;
		foru(i, 0, len + 1) {
			if (block[(i + blockex) % len] && cnt) {
				ans *= dp[cnt][!startWithA];
				cnt = 0;
			}
			else if (!cnt && !block[(i + blockex) % len]) {
				startWithA = (sr[(i + blockex) % len] == 'A');
				cnt = 1;
			}
			else if (!block[(i + blockex) % len])cnt++;
		}
		cout << ans << endl;
	}

	return 0;
}