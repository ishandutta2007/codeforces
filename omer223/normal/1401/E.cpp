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
template<class T>
struct fen {
	vector<T> fenwick;
	int size;
	fen(int sz) {
		size = sz;
		fenwick.resize(size);
		foru(i, 0, size)add(i, 1);
	}
	fen(vector<T> arr) {
		size = arr.size();
		fenwick.resize(size);
		foru(i, 0, size)fenwick[i](0);
		foru(i, 0, size)update(i, arr[i]);
	}
	void add(int index, T add) {
		for (int k = index; k < size; k |= (~k & -~k)) {
			fenwick[k] = fenwick[k] + add;
		}
	}
	void update(int index, T nval) {
		add(index, nval - rangeQuery(index, index));
	}
	T query(int to) {
		T sum = 0;
		for (int curr = to + 1; curr > 0; curr ^= (curr & -curr)) {
			sum = sum + fenwick[curr - 1];
		}
		return sum;
	}
	T rangeQuery(int from, int to) {
		if (!from)return query(to);
		return query(to) - query(from - 1);
	}
	void print() {
		foru(i, 0, size) cout << query(i) << " ";
		cout << endl;
	}
};


const int MX = 1e6;
int n, m;
vector<pii> segd, segu;
vector<pair<pii, int>> nsegd, nsegu;
vector<pii> hori[2];
ll tot = 1;

void foo0() {
	int dsz = segd.size();
	if (!dsz)return;
	sort(segd.begin(), segd.end());
	fen<int> tre(dsz);
	foru(i, 0, dsz)nsegd.pb({ {segd[i].second,segd[i].first},i });
	sort(nsegd.begin(), nsegd.end());
	int ind = 0;
	for (pii p : hori[0]) {//HROI1
		while (ind < dsz&&nsegd[ind].first.first < p.first)tre.add(nsegd[ind++].second, -1);
		int l = 1, r = dsz, mid, bst = -1;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			if (segd[mid - 1].first <= p.second) {
				bst = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (bst != -1)tot += tre.query(bst - 1);
	}
	ind = 0;
	fen<int> tre2(dsz);
	for (pii p : hori[1]) {
		while (ind < dsz&&nsegd[ind].first.first < p.first)tre2.add(nsegd[ind++].second, -1);
		int l = 1, r = dsz, mid, bst = -1;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			if (segd[mid - 1].first >= p.second) {
				bst = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if (bst != -1)tot += tre2.rangeQuery(bst - 1, dsz - 1);
	}
}

void foo1() {
	int usz = segu.size();
	if (!usz)return;
	foru(i, 0, 2)sort(hori[i].rbegin(), hori[i].rend());
	sort(segu.begin(), segu.end());
	fen<int> tre(usz);
	foru(i, 0, usz)nsegu.pb({ {segu[i].second,segu[i].first},i });
	sort(nsegu.rbegin(), nsegu.rend());
	int ind = 0;
	for (pii p : hori[0]) {//HROI1
		while (ind < usz&&nsegu[ind].first.first > p.first)tre.add(nsegu[ind++].second, -1);
		int l = 1, r = usz, mid, bst = -1;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			if (segu[mid - 1].first <= p.second) {
				bst = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (bst != -1)tot += tre.query(bst - 1);
	}
	ind = 0;
	fen<int> tre2(usz);
	for (pii p : hori[1]) {//HROI1
		while (ind < usz&&nsegu[ind].first.first > p.first)tre2.add(nsegu[ind++].second, -1);
		int l = 1, r = usz, mid, bst = -1;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			if (segu[mid - 1].first >= p.second) {
				bst = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if (bst != -1)tot += tre2.rangeQuery(bst - 1, usz - 1);
	}
}

int main() {
	fast;
	cin >> n >> m;
	int a, b, c;
	foru(i, 0, n) {
		cin >> a >> b >> c;
		if (b == 0)segd.pb(mp(a, c));
		else segu.pb(mp(a, b));
		if (b == 0 && c == MX)tot++;
	}
	foru(i, 0, m) {
		cin >> a >> b >> c;
		if (b == 0)hori[0].pb(mp(a, c));
		else hori[1].pb(mp(a, b));
		if (b == 0 && c == MX)tot++;
	}
	foru(i, 0, 2)sort(hori[i].begin(), hori[i].end());
	foo0();
	foo1();
	cout << tot << endl;
	return 0;
}