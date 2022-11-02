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
#include <unordered_map>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }

const int sz = 200;
int v[3][sz], p[3];
ll dp[sz + 1][sz + 1][sz + 1];

int main() {
	fast;
	foru(i, 0, 3)cin >> p[i];
	foru(i, 0, 3) {
		foru(j, 0, p[i])cin >> v[i][j];
		sort(v[i], v[i] + p[i]);
	}
	for (int i = 0; i <= p[0]; i++) {
		for (int j = 0; j <= p[1]; j++) {
			for (int k = 0; k <= p[2]; k++) {
				if (i && j)dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + v[0][i - 1] * v[1][j - 1]);
				if (k && j)dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + v[2][k - 1] * v[1][j - 1]);
				if (i && k)dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + v[0][i - 1] * v[2][k - 1]);
			}
		}
	}
	cout << dp[p[0]][p[1]][p[2]] << endl;
	return 0;
}