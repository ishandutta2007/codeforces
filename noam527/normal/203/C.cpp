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
const int md = 1e9 + 7;
const long long hs = 137;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

ll n, d, a, b, x, y;
vector<pair<ll, int>> u;
vector<int> ans;

int main() {
	fast;
	cin >> n >> d >> a >> b;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		u.push_back({ a*x + b*y, i + 1 });
	}
	sort(u.begin(), u.end());
	ll i = 0, sum = 0;
	while (i < n && sum <= d)
		sum += u[i].first, ans.push_back(u[i].second), i++;
	if (sum <= d) {
		cout << ans.size() << endl;
		for (auto i : ans) cout << i << " "; cout << endl;
		return 0;
	}
	cout << ans.size() - 1 << endl;
	for (int i = 0; i < ans.size() - 1; i++) cout << ans[i] << " "; cout << endl;
}