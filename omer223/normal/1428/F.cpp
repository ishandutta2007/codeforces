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
#include <list>
#include <bitset>
#include <queue>

using namespace std;
using T = int;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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


vector<int> lsuf;
string s;
int n;

void los() {
	foru(i, 0, n) {
		if (!i)lsuf[i] = (s[i] == '1');
		else if (s[i] == '0')lsuf[i] = 0;
		else lsuf[i] = lsuf[i - 1] + 1;
	}
}

int main() {
	fast;
	cin >> n >> s;
	lsuf.resize(n);
	los();
	rmq tre(lsuf);
	ll tot = 0, prv = 0;
	foru(i, 0, n) {
		if (s[i] == '0')tot += prv;
		else if (!i) {
			tot++;
			prv = 1;
		}
		else {
			ll cur = 0;
			int l = 1, r = i, mid, bst = -1;
			while (l <= r) {
				mid = (l + r + 1) / 2;
				if (tre.query(mid - 1, i - 1) >= lsuf[i]) {
					bst = mid - 1;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			if (bst != -1) bst -= (lsuf[i] - 1);
			cur = prv + i - bst;
			prv = cur;
			tot += cur;
		}
	}
	cout << tot << '\n';
	return 0;
}