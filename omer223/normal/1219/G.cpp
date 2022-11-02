#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e5;
vector<ll> r, c;
vector<vector<ll>> a;
ll tmp[sz];
int n, m;

void init() {
	cin >> n >> m;
	r.resize(n);
	fill(r.begin(), r.end(), 0LL);
	c.resize(m);
	fill(c.begin(), c.end(), 0LL);
	a.resize(n);
	foru(i, 0, n) {
		a[i].resize(m);
		fill(a[i].begin(), a[i].end(), 0LL);
	}
	foru(i, 0, n) {
		foru(j, 0, m) {
			cin >> a[i][j];
			r[i] += a[i][j];
			c[j] += a[i][j];
		}
	}
}

inline ll top(int size, int amt) {
	vector<ll> cur(amt, 0);
	foru(i, 0, size) {
		foru(j, 0, amt) {
			if (tmp[i] > cur[j]) {
				ford(k, amt - 1, j + 1)
					cur[k] = cur[k - 1];
				cur[j] = tmp[i];
				break;
			}
		}
	}
	ll ret = 0;
	for (ll x : cur)ret += x;
	return ret;
}

int main() {
	fast;
	init();
	ll tmpans, ans = 0, cand = 0;
	foru(i, 0, n)tmp[i] = r[i];
	ans = top(n, 4);
	foru(i, 0, m)tmp[i] = c[i];
	ans = max(ans, top(m, 4));
	tmpans = 0;
	cand = 0;
	foru(i, 0, n) {
		cand = r[i];
		foru(j, 0, m)tmp[j] = c[j] - a[i][j];
		cand += top(m, 3);
		tmpans = max(cand, tmpans);
	}
	ans = max(ans, tmpans);
	cand = 0;
	tmpans = 0;
	foru(i, 0, m) {
		cand = c[i];
		foru(j, 0, n)tmp[j] = r[j] - a[j][i];
		cand += top(n, 3);
		tmpans= max(cand, tmpans);
	}
	ans = max(ans, tmpans);
	if (n > m) {
		vector<vector<ll>> b(m, vector<ll>(n));
		foru(i, 0, n) {
			foru(j, 0, m)a[i][j] = b[j][i];
		}
		swap(r, c);
		swap(n, m);
		swap(b, a);
	}
	if (n != 1) {
		foru(i, 0, n) {
			foru(j, i + 1, n) {
				cand = r[i] + r[j];
				foru(k, 0, m)tmp[k] = c[k] - a[i][k] - a[j][k];
				cand += top(m, 2);
				ans = max(cand, ans);
			}
		}
	}
	cout << ans << endl;
	return 0;
}