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
const long long hs = 149;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, mx = -1;
vector<string> s;

int main() {
	fast;
	cin >> n;
	s.resize(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < 7; i++) {
		int curr = 0;
		for (auto &j : s)
			curr += in(j[i]);
		mx = max(mx, curr);
	}
	cout << mx << endl;
}