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

#define int LL

int get2(int ans, int rem, int ai) {
	int cur = min(ai / 2, ans * 3);

	int best = -1,
		bestans = -1;
	for (int t = max(0LL, cur - 5); t <= cur; t++) {
		int newans = ans;
		int newai = ai;
		newans += t;
		newai -= t * 2;
		newans -= (t + 2) / 3;
		newans += newai / 3;
		if (newans > bestans)
			bestans = newans, best = t;
	}
	return best;
}

int get1(int ans, int rem, int ai) {
	int mx = min(rem, ai / 2);
	int best = -1,
		bestans = -1;

	for (int cur = max(0LL, mx - 5); cur <= mx; cur++) {
		int newans = ans;
		int newrem = rem;
		int newai = ai;
		newans += cur;
		newrem -= cur;
		newai -= cur * 2;

		int cur2 = get2(newans, newrem, newai);

		newans += cur2;
		newai -= cur2 * 2;
		newans -= (cur2 + 2) / 3;
		newrem += ((cur2 + 2) / 3 * 3) - cur2;
		newrem += newai % 3;
		newans += newai / 3;

		if (newans > bestans)
			bestans = newans, best = cur;
	}
	return best;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	int rem = 0;
	for (int i = 0; i < n; i++) {
		int pans = ans;
		int cur = min(rem, a[i] / 2);
		cur = get1(ans, rem, a[i]);
		ans += cur;
		rem -= cur;
		a[i] -= cur * 2;

		cur = get2(ans, rem, a[i]);

		ans += cur;
		a[i] -= cur * 2;
		ans -= (cur + 2) / 3;
		rem += ((cur + 2) / 3 * 3) - cur;
		rem += a[i] % 3;
		ans += a[i] / 3;
	}
	cout << ans << endl;
	return 0;
}