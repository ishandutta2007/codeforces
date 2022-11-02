
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
#include <bitset>
#include <unordered_map>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef pair<ld, pii> pp;

template<class T>
struct rminq {
	vector<vector<T>> a;
	vector<int> logs;
	int dep, len;
	rminq(vector<T> arr) {
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

template<class T>
struct rmaxq {
	vector<vector<T>> a;
	vector<int> logs;
	int dep, len;
	rmaxq(vector<T> arr) {
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
				else a[i][j] = max(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
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
		return max(a[mylen][l], a[mylen][r - (1 << mylen) + 1]);
	}
};

int main() {
	fast;
	int n;
	vector<int> a, b;
	cin >> n;
	a.resize(n);
	b.resize(n);
	foru(i, 0, n)cin >> a[i];
	foru(i, 0, n)cin >> b[i];
	rminq<int> rb(b);
	rmaxq<int> ra(a);
	ll tot = 0;
	foru(r, 0, n) {
		int bl = 1, br = r + 1, mid, bst = -1;
		while (bl <= br) {
			mid = (bl + br + 1) / 2;
			int aq = ra.query(mid - 1, r), bq = rb.query(mid - 1, r);
			if (aq >= bq) {
				bl = mid + 1;
				if (aq == bq)bst = mid - 1;
			}
			else br = mid - 1;
		}
		if (bst == -1)continue;
		int bstl = -1;
		bl = 1, br = r + 1;
		while (bl <= br) {
			mid = (bl + br + 1) / 2;
			int aq = ra.query(mid - 1, r), bq = rb.query(mid - 1, r);
			if (aq > bq)bl = mid + 1;
			else if (aq < bq)br = mid - 1;
			else {
				bstl = mid - 1;
				br = mid - 1;
			}
		}
		tot += (bst - bstl + 1);
	}
	cout << tot << endl;
	return 0;
}