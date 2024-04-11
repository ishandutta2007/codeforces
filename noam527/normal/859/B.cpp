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

int n, sz;

int main() {
	fast;
	cin >> n;
	sz = floor(sqrt(n)), n -= sz * sz;
	if (n == 0) cout << sz * 4 << endl;
	else if (n <= sz) cout << sz * 4 + 2 << endl;
	else cout << sz * 4 + 4 << endl;
}