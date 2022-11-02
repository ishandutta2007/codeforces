#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <unordered_map>
#include <queue>

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
		if (l > r || l < 0 || r >= len)return 1e15;
		int mylen = logs[r - l + 1];
		return min(a[mylen][l], a[mylen][r - (1 << mylen) + 1]);
	}
};

const int sz = 1e6;
int a[sz];
int n;

bool foo() {
	bool wrong = 0;
	ll sm[2] = { 0 }, smtot[2];
	foru(i, 0, n) {
		sm[i & 1] += a[i];
		if (sm[i & 1] < sm[(i + 1) & 1])wrong = 1;
	}
	if (sm[0] == sm[1] && !wrong) {
		return 1;
	}
	else {
		if (sm[0] != sm[1]) {
			vector<ll> dif(n, 1e15), difo(n, 1e15), dife(n, 1e15);
			sm[0] = sm[1] = 0;
			foru(i, 0, n) {
				sm[i & 1] += a[i];
				if (i) dif[i] = -dif[i - 1] + a[i];
				else dif[i] = a[i];
				if (i & 1)difo[i] = dif[i];
				else dife[i] = dif[i];
			}
			rmq<ll> tt(dif), te(dife), to(difo);
			foru(i, 0, n - 1) {
				ll x = sm[i & 1] + (a[i + 1] - a[i]), y = sm[(i + 1) & 1] + (a[i] - a[i + 1]);
				if (x != y)continue;
				if (tt.query(0, i - 1) < 0)continue;
				else {
					if (i & 1) {
						if (difo[i] - a[i] + a[i + 1] < 0)continue;
						if (to.query(i + 1, n - 1) + 2 * a[i + 1] - 2 * a[i] < 0 || te.query(i + 1, n - 1) + 2 * a[i] - 2 * a[i + 1] < 0)continue;
						return 1;
					}
					else {
						if (dife[i] - a[i] + a[i + 1] < 0)continue;
						if (te.query(i + 1, n - 1) + 2 * a[i + 1] - 2 * a[i] < 0 || to.query(i + 1, n - 1) + 2 * a[i] - 2 * a[i + 1] < 0)continue;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

void solve() {
	cin >> n;
	foru(i, 0, n) {
		cin >> a[i];
	}
	foru(rep, 0, 2) {
		if (foo()) {
			cout << "YES\n";
			return;
		}
		reverse(a, a + n);
	}
	cout << "NO\n";
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}