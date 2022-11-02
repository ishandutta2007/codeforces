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
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) {
	if (!b)return 1;
	ll tmp = modpow(a, b / 2);
	tmp *= tmp;
	if (b & 1)tmp *= a;
	return tmp;
}
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
template<class T>
struct rmq {
	vector<vector<T>> a;
	vector<int> logs;
	int dep, len;
	rmq(vector<T> arr) {
		len = arr.size();
		dep = 0;
		int tmp = len;
		while (tmp) {
			tmp >>= 1;
			dep++;
		}
		a.resize(dep);
		foru(i, 0, dep) {
			a[i].resize(len);
			for (int j = 0; j + (1 << i) <= len; j++) {
				if (!i)a[i][j] = arr[j];
				else a[i][j] = min(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
			}
		}
		initLogs();
	}
	void initLogs() {
		logs.resize(len + 1);
		logs[1] = 0;
		foru(i, 2, len + 1)logs[i] = logs[i >> 1] + 1;
	}
	T query(int l, int r) {
		int mylen = logs[r - l + 1];
		return min(a[mylen][l], a[mylen][r - (1 << mylen) + 1]);
	}
};
int d2(int r) { //<=
	if (r & 1)return r / 2;
	return r / 2 - 1;
}
template<class T>
struct segmentree {
	vector<T> segment;
	int size;
	segmentree(int sz) {
		size = sz;
		segment.resize(2 * size);
		foru(i, 0, 2 * size)segment[i] = 1e9 + 5;
	}
	segmentree(vector<T> arr) {
		size = arr.size();
		segment.resize(2 * size);
		for (int k = 0; k < size; k++)
			segment[size + k] = arr[k];
		for (int k = size - 1; k > 0; k--)
			segment[k] = min(segment[2 * k], segment[2 * k + 1]);
	}
	void update(int index, T val) {
		int t = index + size;
		segment[t] = val;
		while (t > 1) {
			t >>= 1;
			segment[t] = min(segment[2 * t], segment[2 * t + 1]);
		}
	}
	void add(int index, T val) {
		int t = index + size;
		segment[t] = segment[t] + val;
		while (t > 1) {
			t >>= 1;
			segment[t] = min(segment[2 * t], segment[2 * t + 1]);
		}
	}
	T query(int fromIncluded, int toNotIncluded) {
		T sum(1e9+5);
		fromIncluded += size;
		toNotIncluded += size;
		while (fromIncluded < toNotIncluded) {
			if (fromIncluded % 2 == 1) {
				sum = min(sum, segment[fromIncluded]);
				fromIncluded++;
			}
			if (toNotIncluded % 2 == 1) {
				sum = min(sum, segment[toNotIncluded - 1]);
				toNotIncluded--;
			}
			fromIncluded /= 2;
			toNotIncluded /= 2;
		}
		return sum;
	}
};
vector<int> a;
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, tmp,mx=0,mn=1e9;
	cin >> n;
	foru(i, 0, n) {
		cin >> tmp;
		a.pb(tmp);
		mx = max(mx, tmp);
		mn = min(mn, tmp);
	}
	if (mn > d2(mx)) {
		foru(i, 0, n)cout << -1 << " ";
		cout << endl;
		return 0;
	}
	foru(i, 0, n)a.pb(a[i]);
	rmq<int> tree(a);
	segmentree<int> seg(2*n);
	vector<pii> parr;
	foru(i, 0, n)parr.pb(mp(a[i], i));
	sort(parr.rbegin(), parr.rend());
	foru(i, 0, n) {
		int index = parr[i].second, target = d2(parr[i].first), l = index + 1, r = 2 * n, mid, bst = -1;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			if (tree.query(index, mid-1) <= target) {
				bst = mid - 1;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if (bst == -1) {
			int ans = seg.query(index + 1, 2 * n);
			seg.update(index, ans);
			seg.update(index + n, ans + n);
		}
		else {
			int possible = seg.query(index + 1, bst);
			seg.update(index, min(possible, bst));
			seg.update(index + n, min(possible, bst) + n);
		}
	}
	foru(i, 0, n)cout << seg.segment[i + 2*n] - i << " ";
	return 0;
}