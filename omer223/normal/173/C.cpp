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
#include <bitset>
#include <numeric>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

ll n, m;
int arr[500][500], prow[500][500], pcol[500][500], dp[250][500][500];

int sum(int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		if (y2 < y1) return 0;
		if (y1 == 0) return prow[x2][y2];
		else return prow[x2][y2] - prow[x1][y1 - 1];
	}
	else if (y1 == y2) {
		if (x2 < x1)return 0;
		if (x1 == 0) return pcol[x2][y2];
		else return pcol[x2][y2] - pcol[x1 - 1][y1];
	}
	return 0;
}

int square(int x1, int y1, int x2, int y2) {
	int tt = 0;
	tt += sum(x1, y1, x1, y2);
	tt += sum(x2, y1, x2, y2);
	tt += sum(x1 + 1, y1, x2 - 1, y1);
	tt += sum(x1 + 1, y2, x2 - 1, y2);
	return tt;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int res = INT_MIN;
	cin >> n >> m;
	foru(i, 0, n) { foru(j, 0, m)cin >> arr[i][j]; }
	foru(i, 0, n) {
		foru(j, 0, m) {
			if (j == 0) prow[i][j] = arr[i][j];
			else prow[i][j] = prow[i][j - 1] + arr[i][j];
		}
	}
	foru(j, 0, m) {
		foru(i, 0, n) {
			if (i == 0) pcol[i][j] = arr[i][j];
			else pcol[i][j] = pcol[i - 1][j] + arr[i][j];
		}
	}
	for (int k = 1; 2 * k - 1 <= min(m, n); k++) {
		for (int i = 0; i + 2 * k - 1 <= n; i++) {
			for (int j = 0; j + 2 * k - 1 <= m; j++) {
				if (k == 1) dp[k][i][j] = arr[i][j];
				else if (k == 2) dp[k][i][j] = sum(i, j, i, j + 2) + sum(i + 2, j, i + 2, j + 2) + arr[i + 1][j + 2];
				else {
					int len = 2 * k - 1;
					dp[k][i][j] = square(i, j, i + len - 1, j + len - 1) - arr[i + 1][j] + arr[i + 2][j + 1] +dp[k-2][i + 2][j + 2];
				}
				if (k > 1)res = max(res, dp[k][i][j]);
			}
		}
	}
	cout << res << endl;
}