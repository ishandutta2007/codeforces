#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

int n;

int main() {
	fast;
	cin >> n;
	vector<int> a(2 * n);
	for (int i = 0; i < 2 * n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	if (a[n - 1] == a[n]) cout << "NO" << endl;
	else cout << "YES" << endl;
}