#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

struct matrix {
	vector<vector<int>> a;
	void resize(int n, int m) {
		a.resize(n, vector<int>(m, 0));
	}
	int sum() {
		int rtn = 0;
		for (auto &i : a) for (auto &j : i) rtn = (rtn + j) % md;
		return rtn;
	}
	matrix mult(matrix &m, matrix &n) {
		matrix rtn;
		rtn.resize(m.a.size(), n.a[0].size());
		for (int i = 0; i < rtn.a.size(); i++)
			for (int j = 0; j < rtn.a[i].size(); j++)
				for (int k = 0; k < n.a.size(); k++)
					rtn.a[i][j] = (rtn.a[i][j] + (ll)m.a[i][k] * n.a[k][j]) % md;
		return rtn;
	}
	matrix pow(ll e) {
		matrix ans;
		ans.resize(a.size(), a[0].size());
		for (int i = 0; i < a.size(); i++)
			ans.a[i][i] = 1;
		while (e) {
			if (e & 1) ans = mult(ans, *this);
			e /= 2, *this = mult(*this, *this);
		}
		return ans;
	}
};

int good(ll x, ll y) {
	ll z = x ^ y, rtn = 0;
	for (ll i = 1, j = 0; j < 63; j++, i <<= 1)
		if (z & i) rtn++;
	if (rtn % 3 == 0) return 1;
	return 0;
}

int n;
ll k, a[101];

int main() {
	fast;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	matrix adj;
	adj.resize(n, n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) adj.a[i][j] = good(a[i], a[j]);
	cout << adj.pow(k - 1).sum() << endl;
}