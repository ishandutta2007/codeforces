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
const int sz = 1e3 + 5;
int a[sz], n;

int findMex() {
	vi cnt(n + 1, 0);
	foru(i, 0, n)cnt[a[i]]++;
	foru(i, 0, n + 1) {
		if (!cnt[i])return i;
	}
}

void solve() {
	cin >> n;
	foru(i, 0, n)cin >> a[i];
	vi ans;
	foru(i, 0, n) {
		int mex = findMex();
		if (mex == n) {
			int my = -1;
			foru(i, 0, n) {
				if (a[i] != i) {
					my = i;
					break;
				}
			}
			if (my == -1)break;
			ans.pb(my + 1);
			a[my] = n;
			mex = findMex();
		}
		ans.pb(mex + 1);
		a[mex] = mex;
	}
	cout << ans.size() << endl;
	for (int k : ans)cout << k << " ";
	cout << endl;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int t, n;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}