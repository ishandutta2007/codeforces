#define MOD 1000000007
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
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

int a[100];

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int t, n, k, mx, mn;
	us<int> seen;
	vector<int> seenvec;
	cin >> t;
	while (t--) {
		seen.clear();
		seenvec.clear();
		cin >> n >> k;
		FOR(i, n) {
			cin >> a[i];
			if (seen.find(a[i]) == seen.end()) {
				seen.insert(a[i]);
				seenvec.pb(a[i]);
			}
		}
		vector<int> ans;
		if (seen.size() > k) cout << -1 << endl;
		else {
			FOR(i, n) {
				FOR(j, k) {
					if (j >= seenvec.size()) ans.pb(seenvec.back());
					else ans.pb(seenvec[j]);
				}
			}
			cout << ans.size() << endl;
			for (auto x : ans) cout << x << " ";
			cout << endl;
		}
		
	}
	return 0;
}