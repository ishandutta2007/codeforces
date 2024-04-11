#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <bitset>

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

const int sz = 1e5;
int n;
vector<pii> a;
ll dp[sz], sum = 0;

int main() {
	fast;
	cin >> n;
	a.resize(n);
	foru(i, 0, n - 1) {
		cin >> a[i].first; a[i].first--; a[i].second = i;
	}
	a[n - 1].first = n - 1;
	a[n - 1].second = n - 1;
	rmq<pii> myrmq(a);
	ford(i, n - 2, 0) {
		int until = a[i].first;
		if (until == n - 1)dp[i] = until - i;
		else {
			pii x = myrmq.query(i + 1, until);
			int teleTo = x.second;
			dp[i] = teleTo - i;
			dp[i] += (n - 1 - teleTo + dp[teleTo]);
			dp[i] -= (until - teleTo);
		}
		sum += dp[i];
	}
	cout << sum << '\n';
	return 0;
}