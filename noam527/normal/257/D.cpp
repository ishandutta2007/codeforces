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

bool take[100000];
int curr = 0, a[100000], n;

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = n - 1; i >= 0; i--) {
		if (curr > 0)
			take[i] = true, curr -= a[i];
		else
			take[i] = false, curr += a[i];
	}
	for (int i = 0; i < n; i++)
		if (take[i] != (curr > 0))
			cout << "+";
		else
			cout << "-";
	return 0;
}