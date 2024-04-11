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
#include <tuple>
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
#include <math.h>
#include <cmath>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef tuple<ll, ll, ll> tll;
typedef unsigned long long ull;
typedef vector<ll> vll;
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
const int sz = 2e5 + 5;
ll b[sz], c[sz];
ll n, m, s, mxstudent = -1, mxwork = -1;
pll a[sz];
vector<pll> tmpvec;
tll stud[sz];

bool is(int days) {
	ll price = 0;
	int amt = n / days;
	if (n%days)amt++;
	if (amt > n)return 0;
	int sptr = m - 1, workptr = n - 1;
	set<pll> goodstds;
	tmpvec.clear();
	while (workptr >= 0) {
		ll currmx = a[workptr].first;
		while (sptr >= 0 && get<0>(stud[sptr]) >= currmx) {
			goodstds.insert(mp(get<1>(stud[sptr]), get<2>(stud[sptr])));
			sptr--;
		}
		if (goodstds.empty())return false;
		int cnt = 0;
		pll mystd = *goodstds.begin();
		price += mystd.first;
		while (cnt < days&&workptr >= 0) {
			tmpvec.pb(mp(a[workptr].second,mystd.second));
			cnt++;
			workptr--;
		}
		goodstds.erase(mystd);
	}
	return price <= s;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n >> m >> s;
	swap(n, m);
	foru(i, 0, n) {
		cin >> a[i].first; mxwork = max(mxwork, a[i].first);
		a[i].second = i + 1;
	}
	foru(i, 0, m) {
		cin >> b[i]; mxstudent = max(mxstudent, b[i]);
	}
	foru(i, 0, m) {
		cin >> c[i];
		get<0>(stud[i]) = b[i];
		get<1>(stud[i]) = c[i];
		get<2>(stud[i]) = i + 1;
	}
	sort(a, a + n);
	sort(stud, stud + m);
	if (mxstudent < mxwork) {
		cout << "NO" << endl;
		return 0;
	}
	ll l = 1, r = n, mid;
	bool good = false;
	vector<pll> bst;
	while (l <= r) {
		mid = (l + r + 1) / 2;
		if (is(mid)) {
			good = true;
			bst = tmpvec;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if (!good) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	sort(bst.begin(), bst.end());
	for (auto x : bst) cout << x.second << " ";
	cout << endl;
	return 0;
}