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

const int maxn = 2e6 + 10;
int cnt[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[--x]++;
	}
	int ans = 0;
	int cur = 0;
	int prev = 0;
	for (int i = 0; i < maxn; i++) {
		if (cnt[i] == 0) {
			if (cur) {
				if (cur <= prev)
					ans += cur, cur = 0, prev = 1;
				else
					ans += min(cur, 1 + prev), cur = 0, prev = 0;
			}
			else
				prev = 1;
		}
		else
			cur += cnt[i] - 1, ans++;
	}
	cout << ans << endl;
	return 0;
}