#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;

int t[1000][1000];
int answer[200000];

int main() {
	ios::sync_with_stdio(false);

	int x, y;
	cin >> x >> y;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			t[i][j] = INF;
		}
	}

	int x0, y0;
	cin >> x0 >> y0;
	x0--;
	y0--;
	t[x0][y0] = 0;

	string s;
	cin >> s;
	int k = s.length();
	int cur_t = 0;
	for (int i = 0; i < k; i++) {
		char c = s[i];
		cur_t++;
		if (c == 'L') {
			y0--;
		} else if (c == 'R') {
			y0++;
		} else if (c == 'U') {
			x0--;
		} else if (c == 'D') {
			x0++;
		}

		if (0 <= x0 && x0 < x && 0 <= y0 && y0 < y) {
			t[x0][y0] = min(t[x0][y0], cur_t);
		} else {
			if (c == 'L') {
				y0++;
			} else if (c == 'R') {
				y0--;
			} else if (c == 'U') {
				x0++;
			} else if (c == 'D') {
				x0--;
			}
		}
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (t[i][j] == INF) {
				answer[k]++;
			} else {
				answer[t[i][j]]++;
			}
		}
	}

	for (int i = 0; i <= k; i++) {
		cout << answer[i] << " ";
	}
	cout << endl;

    return 0;
}