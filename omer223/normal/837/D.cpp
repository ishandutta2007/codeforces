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

const int sz = 2e2 + 5, hsz = 5000;
ll n, k,sh=0;
pii a[sz];
int dp[sz][hsz], pp[sz][hsz];
int foo() {
	ll cr = 0;
	for (int j = 0; j <= k; j++) {
		for (int h = 0; h <= sh; h++) {
			if (!h&&!j)pp[j][h] = 0;
			else pp[j][h] = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		cr += a[i].second;
		for (int j = 1; j <= k && j <= i; j++) {
			for (int h = 0; h <= cr; h++) {
				if (h < a[i].second||pp[j-1][h-a[i].second]==-1)dp[j][h] = pp[j][h];
				else dp[j][h] = max(pp[j][h], pp[j - 1][h - a[i].second] + a[i].first);
			}
		}
		for (int j = 1; j <= k && j <= i; j++) {
			for (int h = 0; h <= cr; h++) {
				pp[j][h] = dp[j][h];
			}
		}
	}
	int ans = 0;
	foru(i, 0, sh+1) {
		ans = max(ans, min(i, dp[k][i]));
	}
	return ans;
}
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n >> k;
	ll r;
	foru(i, 0, n) {
		cin >> r;
		while (r&&r % 2 == 0) {
			a[i+1].first++;
			r /= 2;
		}
		while (r&&r % 5 == 0) {
			a[i+1].second++;
			r /= 5; sh++;
		}
	}
	cout << foo() << endl;
	return 0;
}