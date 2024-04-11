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
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

bool test(vector<int> &a) {
	for (int i = 0; i < a.size(); i++) if (a[i] != i) return false;
	return true;
}

int main() {
	fast;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j += 2) a[j] = (a[j] + 1) % n;
		for (int j = 1; j < n; j += 2) a[j] = (a[j] - 1 + n) % n;
		if (test(a)) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}