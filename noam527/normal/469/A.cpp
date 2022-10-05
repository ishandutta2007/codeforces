#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, x, y;
set<int> I_DONT_NEED_A_SET_HERE;

int main() {
	fast;
	cin >> n >> x;
	while (x--) cin >> y, I_DONT_NEED_A_SET_HERE.insert(y);
	cin >> x;
	while (x--) cin >> y, I_DONT_NEED_A_SET_HERE.insert(y);
	cout << (I_DONT_NEED_A_SET_HERE.size() == n ? "I become the guy." : "Oh, my keyboard!") << endl;
}