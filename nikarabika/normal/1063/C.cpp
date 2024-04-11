//sobskdrbhvk
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const int xxxx = 1e4;
int n;

void solve(int pos = 0, int l = 0, int r = 1000 * 1000 * 1000) {
	string color, color2;
	if (pos == n) {
		cout << l << ' ' << xxxx - 1 << ' '
			<< r << ' ' << xxxx + 1 << endl;
		return;
	}
	if (r - l == 1) {
		cout << l << ' ' << xxxx + 100 << endl;
		cin >> color;
		if (pos == n - 1) {
			if (color == "black")
				cout << r << ' ' << xxxx - 100 << ' '
					<< l << ' ' << xxxx + 200 << endl;
			else
				cout << r << ' ' << xxxx - 100 << ' '
					<< l << ' ' << xxxx + 50 << endl;
			return;
		}
		else {
			if (color == "black") {
				cout << l << ' ' << xxxx + 200 << endl;
				cin >> color2;
				if (color2 == "black")
					cout << r << ' ' << xxxx - 100 << ' '
						<< l << ' ' << xxxx + 300 << endl;
				else
					cout << r << ' ' << xxxx - 100 << ' '
						<< l << ' ' << xxxx + 150 << endl;
			}
			else {
				cout << l << ' ' << xxxx + 50;
				cin >> color2;
				if (color2 == "black")
					cout << r << ' ' << xxxx - 100 << ' '
						<< l << ' ' << xxxx + 75 << endl;
				else
					cout << r << ' ' << xxxx - 100 << ' '
						<< l << ' ' << xxxx + 25 << endl;
			}
			return;
		}
		return;
	}
	int mid = (l + r) >> 1;
	cout << mid << ' ' << xxxx << endl;
	cin >> color;
	if (color == "black")
		solve(pos + 1, mid, r);
	else
		solve(pos + 1, l, mid);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	solve();
	return 0;
}