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

int n, mn = 2e9;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a.second != b.second) return a.second < b.second;
	return a.first < b.first;
}

void check(vector<pair<int, int>> a) {
	sort(a.begin(), a.end(), cmp);
	int s = 0;
	for (int i = 2; i < 2 * n; i += 2) s += a[i + 1].first - a[i].first;
	mn = min(mn, s);
}

int main() {
	fast;
	cin >> n;
	vector<pair<int, int>> a(2*n);
	for (int i = 0; i < a.size(); i++) cin >> a[i].first, a[i].second = 1;
	for (int i = 0; i < 2 * n; i++) for (int j = i + 1; j < 2 * n; j++) {
		a[i].second = a[j].second = 0;
		check(a);
		a[i].second = a[j].second = 1;
	}
	cout << mn << endl;
}