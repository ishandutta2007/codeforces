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

int n, a[100];

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	if (n % 2 == 0 || a[0] % 2 == 0 || a[n - 1] % 2 == 0) cout << "NO" << endl;
	else cout << "YES" << endl;
}