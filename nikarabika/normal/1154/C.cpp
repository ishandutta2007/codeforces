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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	int which[] = {0, 0, 1, 2, 0, 2, 1};
	int ans = 0;
	for (int i = 6; i >= 0; i--) {
		a[which[i]]--;
		if (a[which[i]] < 0)
			break;
		int week = min(min(a[0] / 3, a[1] / 2), a[2] / 2);
		int b[3];
		for (int j = 0; j < 3; j++)
			b[j] = a[j] - week * (2 + (j == 0));
		for (int j = 0; j < 7; j++) {
			smax(ans, 7 - i + week * 7 + j);
			b[which[j]]--;
			if (b[which[j]] < 0)
				break;
		}
	}
	cout << ans << endl;
	return 0;
}