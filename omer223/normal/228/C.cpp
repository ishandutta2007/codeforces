#define MOD 1000000007
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
#include <cmath>
#include <math.h>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <stack>
#include <numeric>
#include <queue>
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef tuple<int, int, int, int> qu;
typedef unsigned long long ull;
typedef long double ld;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }
void mult(ll &a, ll b) {
	a = ((a % MOD) * (b % MOD)) % MOD;
}
void add(ll &a, ll b) {
	a = ((a % MOD) + (b % MOD)) % MOD;
}
void subtract(ll &a, ll b) {
	if (a >= b)a = (a - b) % MOD;
	else a = (a - b) % MOD + MOD;
}
const int mxN = 5e2 + 5;
bool a[mxN][mxN]; //1 means black
bool dp[mxN][mxN][17][10];//x, y, type (0 means squares), depth (size = 2 ^ depth)
int n, m;
inline bool matchesPattern(int i, int j, int type) {
	bool is = 1;
	is &= ((type & 1) == a[i][j]);
	is &= ((type >> 1) & 1) == a[i][j + 1];
	is &= ((type >> 2) & 1) == a[i + 1][j];
	is &= ((type >> 3) & 1) == a[i + 1][j + 1];
	return is;
}
void input() {
	cin >> n >> m;
	char c;
	foru(i, 0, n) {
		foru(j, 0, m) {
			cin >> c;
			if (c != '.')a[i][j] = 1;
		}
	}
}
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	input();
	int sz = 1, ind = 0;
	while (sz <= n && sz <= m) {
		if (sz == 1) {
			foru(i, 0, n) {
				foru(j, 0, m) dp[i][j][0][ind] = a[i][j];
			}
		}
		else {
			foru(i, 0, n - sz + 1) {
				foru(j, 0, m - sz + 1) dp[i][j][0][ind] = (dp[i][j][0][ind - 1] && dp[i + sz / 2][j][0][ind - 1] &&
					dp[i][j + sz / 2][0][ind - 1] && dp[i + sz / 2][j + sz / 2][0][ind - 1]);
			}
		}
		sz <<= 1;
		ind++;
	}
	foru(type, 1, 17) {
		int sz = 2, ind = 1;
		while (sz <= n && sz <= m) {
			if (ind == 1) {
				foru(i, 0, n - sz + 1) {
					foru(j, 0, m - sz + 1) 
						dp[i][j][type][ind] = matchesPattern(i, j, type - 1);
				}
			}
			else {
				foru(i, 0, n - sz + 1) {
					foru(j, 0, m - sz + 1) {
						bool is = 1;
						if ((type-1) & 1) is &= dp[i][j][0][ind - 1];
						else is &= dp[i][j][type][ind - 1];
						if (((type-1) >> 1) & 1)is &= dp[i][j + sz / 2][0][ind - 1];
						else is &= dp[i][j + sz/2][type][ind - 1];
						if (((type-1) >> 2) & 1)is &= dp[i + sz / 2][j][0][ind - 1];
						else is &= dp[i + sz/2][j][type][ind - 1];
						if (((type-1) >> 3) & 1)is &= dp[i + sz / 2][j + sz / 2][0][ind - 1];
						else is &= dp[i+sz/2][j+sz/2][type][ind - 1];
						dp[i][j][type][ind] = is;
					}
				}
			}
			ind++;
			sz <<= 1;
		}
	}
	ll cnt = 0;
	foru(type, 1, 17) {
		foru(ind, 2, 10) {
			foru(i, 0, n) {
				foru(j, 0, m)cnt += dp[i][j][type][ind];
			}
		}
	}
	cout << cnt << endl;
	return 0;
}