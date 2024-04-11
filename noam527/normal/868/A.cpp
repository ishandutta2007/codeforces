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
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-7, pi = acos(-1);
using namespace std;

string s;
int n;
vector<string> a;
vector<int> b, c;

int main() {
	fast;
	cin >> s >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (auto &i : a) if (i == s) return cout << "YES" << endl, 0;
	for (int i = 0; i < n; i++) {
		if (a[i][0] == s[1]) b.push_back(i);
		if (a[i][1] == s[0]) c.push_back(i);
	}
	if (!b.size() || !c.size()) return cout << "NO" << endl, 0;
	cout << "YES" << endl;
}