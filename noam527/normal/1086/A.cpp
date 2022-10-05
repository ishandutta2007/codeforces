#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int x[3], y[3];
set<pair<int, int>> a;

int main() {
	fast;
	for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];

	int posx = x[0] + x[1] + x[2] - min({ x[0], x[1], x[2] }) - max({ x[0], x[1], x[2] });
	int posy = y[0] + y[1] + y[2] - min({ y[0], y[1], y[2] }) - max({ y[0], y[1], y[2] });
	for (int i = 0; i < 3; i++) {
		int tmpx = posx;
		int tmpy = posy;
		a.insert({ x[i], y[i] });
		while (tmpy != y[i]) {
			a.insert({ tmpx, tmpy });
			if (tmpy > y[i]) {
				tmpy--;
			}
			else tmpy++;
		}
		while (tmpx != x[i]) {
			a.insert({ tmpx, tmpy });
			if (tmpx > x[i]) {
				tmpx--;
			}
			else {
				tmpx++;
			}
		}
	}
	cout << a.size() << endl;
	for (const auto &i : a) cout << i.first << " " << i.second << endl;
}