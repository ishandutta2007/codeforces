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

const int maxn = 2e5 + 10;
LL dp[maxn][10];
int n;

vector<pll> input(int _) {
	multiset<int> maxd[3];
	int len;
	cin >> len;
	for (int i = 0; i < len; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--;
		maxd[fi].insert(se);
		if (sz(maxd[fi]) > 3 / (fi + 1)) {
			auto it = maxd[fi].begin();
			maxd[fi].erase(it);
		}
	}
	vector<pll> result;
	for (int i = 0; i < 3; i++)
		for (auto val : maxd[i]) {
			result.PB(MP(i + 1, val));
		}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int j = 1; j < 10; j++)
		dp[0][j] = -1e18;
	for (int i = 0; i < n; i++) {
		auto vec = input(i);
		memcpy(dp[i + 1], dp[i], sizeof dp[i]);
		for (int p1 = 0; p1 < sz(vec); p1++) if (vec[p1].L < 3)
			for (int p2 = 0; p2 < sz(vec); p2++) if (p2 != p1 and vec[p1].L + vec[p2].L < 3)
				for (int p3 = 0; p3 < sz(vec); p3++) if (p3 != p2 and p3 != p1 and vec[p1].L + vec[p2].L + vec[p3].L <= 3) {
					LL power = vec[p1].R + vec[p2].R + vec[p3].R;
					for (int j = 0; j < 10; j++)
						smax(dp[i + 1][(j + 3) % 10], dp[i][j] + power + (j == 7 ? vec[p3].R : j == 8 ? vec[p2].R : j == 9 ? vec[p1].R : 0));
				}
		for (int p1 = 0; p1 < sz(vec); p1++) if (vec[p1].L < 3)
			for (int p2 = 0; p2 < sz(vec); p2++) if (p2 != p1 and vec[p1].L + vec[p2].L <= 3) {
				LL power = vec[p1].R + vec[p2].R;
				for (int j = 0; j < 10; j++)
					smax(dp[i + 1][(j + 2) % 10], dp[i][j] + power + (j == 8 ? vec[p2].R : j == 9 ? vec[p1].R : 0));
			}
		for (int p1 = 0; p1 < sz(vec); p1++) if (vec[p1].L <= 3) {
			LL power = vec[p1].R;
			for (int j = 0; j < 10; j++)
				smax(dp[i + 1][(j + 1) % 10], dp[i][j] + power + (j == 9 ? vec[p1].R : 0));
		}
	}
	cout << *max_element(dp[n], dp[n] + 10) << '\n';
	return 0;
}