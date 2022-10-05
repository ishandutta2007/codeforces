#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
using namespace std;

int n, a, b, mx = 0;
vector<pair<int, int>> s;

int check(pair<int, int> &c, pair<int, int> &d) {
	if (c.first > a || c.second > b || d.first > a || d.second > b) return -1;
	if (c.first + d.first <= a || c.second + d.second <= b) return c.first * c.second + d.first * d.second;
	return -1;
}

int main() {
	fast;
	cin >> n >> a >> b;
	s.resize(n);
	for (int i = 0; i < n; i++) cin >> s[i].first >> s[i].second;
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
		for (int x = 0; x < 2; x++) {
			mx = max(mx, check(s[i], s[j]));
			swap(s[i].first, s[i].second);
			mx = max(mx, check(s[i], s[j]));
			swap(s[j].first, s[j].second);
		}
	}
	cout << mx << endl;
}