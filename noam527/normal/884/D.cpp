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
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

// I didn't even dis/prove greedy solution and this is just a guess

int n, x;
ll ans = 0;
multiset<ll> s;

void take(int am) {
	ll add = 0;
	while (am--)
		add += *s.begin(), s.erase(s.begin());
	ans += add, s.insert(add);
}

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x, s.insert(x);
	if (n % 2 == 0) take(2), n--;
	while (n > 1) take(3), n -= 2;
	cout << ans << endl;
}