#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
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

int n;
ll sum = 0;
vector<pair<ll, int>> a, b;

void rot() {
	for (int i = n - 1; i > 0; i--)
		swap(a[i], a[i - 1]);
}

bool check(int i = 0, ll s1 = 0, ll s2 = 0) {
	if (s1 == s2 && s1 != 0 && s1 != sum) return true;
	if (i == n) return false;
	return check(i + 1, s1, s2) || check(i + 1, s1 + a[i].first, s2 + b[i].first);
}

bool cmp(pair<ll, int> &a, pair<ll, int> &b) {
	return a.first < b.first;
}
bool cmp2(pair<ll, int> &a, pair<ll, int> &b) {
	return a.second < b.second;
}

int main() {
	fast;
	cin >> n;
	a.resize(n), b.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i, a[i].first++, sum += a[i].first;
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < n; i++) b[i].first = a[i].first, b[i].second = a[i].second;

	for (int i = 0; i < n; i++) {
		rot();
		if (!check()) {
			for (int j = 0; j < n; j++) b[j].first = a[j].first;
			sort(b.begin(), b.end(), cmp2);
			for (auto &j : b) cout << j.first - 1 << " "; cout << endl;
			return 0;
		}
	}
	finish(-1);
}