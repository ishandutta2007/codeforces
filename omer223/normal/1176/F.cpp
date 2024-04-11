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

const int sz = 2e5 + 5;
ll a[sz], dp[sz][10], n;
ll bestCombo[sz][3], hits[sz][3];

void init() {
	int k;
	ll a, b, bst, bsttwo;
	multiset<ll, greater<ll>> ones;
	foru(i, 0, n) {
		cin >> k;
		bst = -1;
		bsttwo = -1;
		ones.clear();
		foru(j, 0, k) {
			cin >> a >> b;
			bst = max(bst, b);
			if (a == 2)bsttwo = max(bsttwo, b);
			else if (a == 1)ones.insert(b);
		}
		bestCombo[i][0] = bst;
		hits[i][0] = bst;
		if (!ones.empty() && (bsttwo > 0 || ones.size() >= 2)) {
			auto x = ones.begin();
			ll val = *x;
			x++;
			if (x == ones.end()) {
				bestCombo[i][1] = val + bsttwo;
				hits[i][1] = max(val, bsttwo);
				bestCombo[i][2] = -1;
			}
			else {
				bestCombo[i][1] = max(val + *x, val + bsttwo);
				hits[i][1] = max(val, max(*x, bsttwo));
				ll hgh = val;
				val += *x;
				x++;
				if (x != ones.end()) {
					bestCombo[i][2] = val + *x;
					hits[i][2] = hgh;
				}
				else {
					bestCombo[i][2] = -1;
				}
			}
		}
		else {
			bestCombo[i][1] = -1;
			bestCombo[i][2] = -1;
		}
	}
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n;
	init();
	ford(i, n - 1, 0) {
		ford(j, 9, 0) {
			dp[i][j] = dp[i + 1][j];
			foru(p, 0, 3) {
				if (bestCombo[i][p] != -1)dp[i][j] = max(dp[i][j], dp[i + 1][(j - p + 9) % 10] + bestCombo[i][p] + (j - p - 1 < 0 ? hits[i][p] : 0));
			}
		}
	}
	cout << dp[0][9] << endl;
	return 0;
}