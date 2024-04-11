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
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

string s;
vector<int> op;
int s1 = 0, s2 = 0, d;

int main() {
	fast;
	cin >> s;
	s1 = in(s[0]) + in(s[1]) + in(s[2]);
	s2 = in(s[3]) + in(s[4]) + in(s[5]);
	d = abs(s1 - s2);
	if (s1 > s2) {
		for (int i = 0; i < 3; i++) op.push_back(in(s[i]));
		for (int i = 3; i < 6; i++) op.push_back(9 - in(s[i]));
	}
	else {
		for (int i = 0; i < 3; i++) op.push_back(9 - in(s[i]));
		for (int i = 3; i < 6; i++) op.push_back(in(s[i]));
	}
	sort(op.begin(), op.end());
	int ans = 0;
	while (d > 0) d -= last(op, 1), op.pop_back(), ans++;
	cout << ans << endl;
}