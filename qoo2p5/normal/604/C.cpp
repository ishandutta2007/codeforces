#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

int n;
bool s[100001];
int d[100001][2][2][2];

void mx(int &a, int &b, int c = 1) {
	a = max(a, b + c);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		char c = getchar();
		if (c == '1') {
			s[i] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 1; j++) {
			for (int k = 0; k <= 1; k++) {
				for (int f = 0; f <= 1; f++) {
					d[i][j][k][f] = d[i - 1][j][k][k];
				}
			}
		}

		for (int f = 0; f <= 1; f++) {
			mx(d[i][s[i]][0][f], d[i - 1][!s[i]][0][f], 1);
		}

		mx(d[i][s[i]][0][1], d[i - 1][!s[i]][1][1], 1);

		mx(d[i][!s[i]][1][1], d[i - 1][s[i]][1][1], 1);
		mx(d[i][!s[i]][1][1], d[i - 1][s[i]][0][0], 1);
	}

	int ans = 0;
	for (int j = 0; j <= 1; j++) {
		for (int k = 0; k <= 1; k++) {
			for (int f = 0; f <= 1; f++) {
				ans = max(ans, d[n][j][k][f]);
			}
		}
	}

	cout << ans << endl;

	return 0;
}