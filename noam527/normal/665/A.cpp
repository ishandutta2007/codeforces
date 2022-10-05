#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(X) (X)[(X).size() - 1]
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
using namespace std;

int a1, t1, a2, t2, m;
string s;

int main() {
	fast;
	cin >> a1 >> t1 >> a2 >> t2 >> s;
	m = 60 * (in(s[0]) * 10 + in(s[1])) + in(s[3]) * 10 + in(s[4]);
	int st = m, en = m + t1, i = 300, ans = 0;
	while (i < 1440) {
		if (i < en && i + t2 > st) ans++;
		i += a2;
	}
	cout << ans << endl;
}