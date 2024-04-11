#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <queue>
#include <numeric>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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
const int sz = 3e5 + 5;
int n;
ll b[sz];
vector<int> h;
ll segment[2 * sz];

inline ll action(const ll& lhs, const ll& rhs) {
	return max(lhs, rhs);
}

void init() {
	for (int k = 0; k < n; k++)
		segment[n + k] = -1e18;
	for (int k = n - 1; k > 0; k--)
		segment[k] = action(segment[2 * k], segment[2 * k + 1]);
}
void update(int index, ll val) {
	int t = index + n;
	segment[t] = val;
	while (t >= 1) {
		t >>= 1;
		segment[t] = action(segment[2 * t], segment[2 * t + 1]);
	}
}
void add(int index, ll val) {
	int t = index + n;
	segment[t] += val;
	while (t > 1) {
		t >>= 1;
		segment[t] = action(segment[2 * t], segment[2 * t + 1]);
	}
}
ll query(int fromIncluded, int toNotIncluded) {
	ll sum = -1e18; //CHECK
	fromIncluded += n;
	toNotIncluded += n;
	while (fromIncluded < toNotIncluded) {
		if (fromIncluded % 2 == 1) {
			sum = action(sum, segment[fromIncluded]);
			fromIncluded++;
		}
		if (toNotIncluded % 2 == 1) {
			sum = action(sum, segment[toNotIncluded - 1]);
			toNotIncluded--;
		}
		fromIncluded /= 2;
		toNotIncluded /= 2;
	}
	return sum;
}
int main() {
	fast;
	cin >> n;
	h.resize(n);
	foru(i, 0, n)cin >> h[i];
	foru(i, 0, n)cin >> b[i];
	init();
	update(0, b[0]);
	rmq<int> rm(h);
	foru(i, 1, n) {
		int l = 1, r = i, mid, bst = i;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			if (h[i] < rm.query(mid - 1, i - 1)) {
				bst = mid - 1;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if (bst == 0)update(i, max(b[i], b[i] + query(0, i)));
		else if (bst == i)update(i, max(b[i] + query(i - 1, i), query(i - 1, i)));
		else update(i, max(b[i] + query(bst - 1, i), query(bst - 1, bst)));
	}
	cout << query(n - 1, n) << '\n';
	return 0;
}