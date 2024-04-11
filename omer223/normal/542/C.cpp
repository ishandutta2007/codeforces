#define MOD 1000000000000000000
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

const int sz = 2e2 + 5;
ll f[sz], m = 0, n, len[sz], alpha[sz];
us<int> cyc, vis;
list<int> radj[sz];
bitset<sz> tmpvis;
ll foo() {
	ll lcm = len[0];
	foru(i, 1, m) lcm = (lcm * len[i]) / gcd(lcm, len[i]);
	ll l=1,r = 1,mid,bst=-1;
	foru(i, 0, m) r = max(r , (ll)ceil(double((alpha[i] * len[i]) / lcm)) + 2);
	while (l <= r) {
		mid = (l + r + 1) / 2;
		ll mult = mid * lcm;
		bool good = 1;
		foru(i, 0, m) {
			if (mult < len[i] * alpha[i]) {
				good = 0;
				break;
			}
		}
		if (good) {
			bst = mult;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return bst;
}

void getCycle(int src) {
	if (tmpvis[src]) {
		int k = src;
		bool first = 1;
		while (first || k != src) {
			first = 0;
			cyc.insert(k);
			k = f[k];
		}
	}
	else {
		tmpvis[src] = 1;
		getCycle(f[src]);
	}
}

void setup() {
	foru(i, 1, n + 1)vis.insert(i);
	while (!vis.empty()) {
		cyc.clear();
		tmpvis.reset();
		getCycle(*vis.begin());
		len[m] = cyc.size();
		queue<pii> q;
		int mxdist = 0;
		for (int k : cyc) q.push(mp(k,0));
		while (!q.empty()) {
			auto x = q.front(); q.pop();
			vis.erase(x.first);
			mxdist = max(mxdist, x.second);
			for (auto y : radj[x.first]) {
				if (cyc.find(y) == cyc.end()) q.push(mp(y, x.second + 1));
			}
		}
		alpha[m] = max(1LL, (mxdist - 1) / len[m] + 1);
		m++;
	}
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n;
	foru(i, 0, n) {
		cin >> f[i + 1];
		radj[f[i + 1]].pb(i + 1);
	}
	setup();
	cout << foo() << endl;
	return 0;
}