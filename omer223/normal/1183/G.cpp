
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include <queue>
#include <set>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef pair<pii, int> comp;
ll modpow(ll a, ll b, ll md) { ll res = 1; a %= md; for (; b; b >>= 1) { if (b & 1)res = res * a%md; a = a * a%md; }return res; }

const int sz = 2e5;
int n;
int candies[sz], goods[sz];

void reset() {
	foru(i, 0, n) {
		candies[i] = 0;
		goods[i] = 0;
	}
}

void solve() {
	cin >> n;
	reset();
	int tmp, f;
	foru(i, 0, n) {
		cin >> tmp >> f; tmp--;
		candies[tmp]++;
		goods[tmp] += f;
	}
	vector<pii> v;//amt, goods
	foru(i, 0, n) {
		if (candies[i]) {
			v.pb(mp(candies[i], goods[i]));
		}
	}
	sort(v.rbegin(), v.rend());
	ll tot = 0, prv;
	int m = v.size();
	vector<int> sizes;
	foru(i, 0, m) {
		if (!i) {
			tot += v[i].first;
			prv = v[i].first;
		}
		else {
			if (v[i].first >= prv - 1) tot += (--prv);
			else {
				tot += v[i].first; prv = v[i].first;
			}
		}
		sizes.pb(prv);
		if (prv == 1)break;
	}
	cout << tot << endl;
	priority_queue<int> pq;//greater?
	size_t sizesSize = sizes.size(), ind = 0;
	int goodtot = 0;
	for (int i = 0; i < sizesSize; i++) {
		while (ind < m&&v[ind].first >= sizes[i]) {
			pq.push(v[ind].second);
			ind++;
		}
		goodtot += min(pq.top(), sizes[i]); pq.pop();
	}
	cout << goodtot << endl;
}

int main() {
	fast;
	int q;
	cin >> q;
	while (q--)solve();
	return 0;
}