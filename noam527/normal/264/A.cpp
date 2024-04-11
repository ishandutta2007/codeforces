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

string s;
vector<int> l, r;
int n = 1;

int main() {
	fast;
	cin >> s;
	for (auto &i : s)
		if (i == 'l')
			l.push_back(n++);
		else
			r.push_back(n++);
	while (l.size())
		r.push_back(l.back()), l.pop_back();
	for (auto &i : r) cout << i << endl;
}