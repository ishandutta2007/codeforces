//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

void draw(int x, int y, int xx, int yy) {
	while (x < xx) {
		cout << x << ' ' << y << '\n';
		++x;
	}
	while (x > xx) {
		cout << x << ' ' << y << '\n';
		--x;
	}
	while (y < yy) {
		cout << x << ' ' << y << '\n';
		++y;
	}
	while (y > yy) {
		cout << x << ' ' << y << '\n';
		--y;
	}
}

int dis(int x, int xx) {
	return x < xx ? xx - x : x - xx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x[3],
	y[3];
	for (int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];
	int ans = 1e6,
		ansi = -1,
		ansj = -1;
	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++) {
			int cur = 1;
			for (int k = 0; k < 3; k++)
				cur += dis(x[k], i) + dis(y[k], j);
			if (cur < ans) {
				ans = cur;
				ansi = i;
				ansj = j;
			}
		}
	cout << ans << endl;
	for (int i = 0; i < 3; i++)
		draw(x[i], y[i], ansi, ansj);
	cout << ansi << ' ' << ansj << '\n';
	return 0;
}