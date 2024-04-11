#define MOD 1000000007
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define FOR(i, n) for (int i = 0; i < n; i++)
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
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }

int arr[3500];
ll maxs[3500], segment[7001];
int sz;
void buildSegment(int size) {
	for (int i = 2 * size - 1; i >= size; i--) segment[i] = maxs[i - size];
	for (int i = size - 1; i > 0; i--) segment[i] = min(segment[2 * i], segment[2 * i + 1]);
}

ll query(int from, int toExcluded) {
	int f = from + sz, t = toExcluded + sz;
	ll res = 1e15;
	while (f < t) {
		if (t % 2 == 1) {
			t--;
			res = min(res, segment[t]);
		}
		if (f % 2 == 1) {
			res = min(res, segment[f]);
			f++;
		}
		t >>= 1; f >>= 1;
	}
	return res;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int t, n, m, k, len, r;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		r = 0;
		FOR(i, n) cin >> arr[i];
		len = n - m + 1;
		k = min(k, m - 1);
		while (r + len < n + 1) {
			maxs[r] = max(arr[r], arr[r + len - 1]);
			r++;
		}
		sz = n - len + 1;
		buildSegment(n - len + 1);
		int ctrlSize = sz - k;
		ll best = 0;
		for (int i = 0; i + ctrlSize - 1 < sz; i++) {
			best = max(best, query(i, i + ctrlSize));
		}
		cout << best << endl;
	}

	return 0;
}