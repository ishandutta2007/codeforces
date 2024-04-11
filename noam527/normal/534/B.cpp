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
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int v1, v2, t, d, ans = 0;

int main() {
	fast;
	cin >> v1 >> v2 >> t >> d;
	for (int i = 0; i < t; i++)
		ans += min(v1 + d * i, v2 + d * (t - 1 - i));
	cout << ans << endl;
}