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
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 149;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

struct item {
	int t, d, p, ind;
	item() {};
	bool operator < (item &x) {
		return d > x.d;
	}
};

int n, dp[101][2002], t[101][2002];
vector<item> a;

int main() {
	fast;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i].t >> a[i].d >> a[i].p, a[i].ind = i + 1;
	sort(a.begin(), a.end());
	for (int i = 0; i < 2002; i++) {
		if (i + a[0].t < a[0].d) dp[0][i] = a[0].p, t[0][i] = 1;
		else dp[0][i] = 0, t[0][i] = 0;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 2002; j++) {
			dp[i][j] = dp[i - 1][j], t[i][j] = 0;
			if (j + a[i].t < a[i].d && dp[i][j] < a[i].p + dp[i - 1][j + a[i].t])
				dp[i][j] = a[i].p + dp[i - 1][j + a[i].t], t[i][j] = 1;
		}
	}

	cout << dp[n - 1][0] << endl;
	vector<int> f;
	int time = 0;
	for (int i = n - 1; i >= 0; i--)
		if (t[i][time]) f.push_back(a[i].ind), time += a[i].t;

	
	cout << f.size() << endl;
	for (auto &i : f) cout << i << " "; cout << endl;
}