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

int n, cnt = 0;
string s;

int main() {
	fast;
	cin >> n >> s;
	for (auto i : s) if (i == 'x') cnt++;
	if (cnt == n / 2) {
		cout << 0 << endl << s << endl;
		return 0;
	}
	if (cnt < n / 2) {
		cout << n / 2 - cnt << endl;
		int i = 0;
		while (cnt < n / 2) {
			if (s[i] == 'X') s[i] = 'x', cnt++;
			i++;
		}
		cout << s << endl;
		return 0;
	}
	cout << cnt - n / 2 << endl;
	int i = 0;
	while (cnt > n / 2) {
		if (s[i] == 'x') s[i] = 'X', cnt--;
		i++;
	}
	cout << s << endl;
}