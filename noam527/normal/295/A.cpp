#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

ll n, m, k, qu[3][100001];

int main() {
	fast;
	cin >> n >> m >> k;
	vector<ll> a(n + 1), qcnt(m + 1, 0);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = n - 1; i > 0; i--) a[i] -= a[i - 1];
	for (int i = 0; i < m; i++)
		cin >> qu[0][i] >> qu[1][i] >> qu[2][i];
	for (int i = 0, l, r; i < k; i++) {
		cin >> l >> r;
		qcnt[l - 1]++, qcnt[r]--;
	}
	for (int i = 1; i < qcnt.size(); i++) qcnt[i] += qcnt[i - 1];
	for (int i = 0; i < m; i++) {
		a[qu[0][i] - 1] += qu[2][i] * qcnt[i];
		a[qu[1][i]] -= qu[2][i] * qcnt[i];
	}

	for (int i = 1; i < n; i++) a[i] += a[i - 1];
	for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}