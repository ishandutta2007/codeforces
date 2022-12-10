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
	int n, k;
	cin >> n >> k;
	int cnt[k] = {0};
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x % k]++;
	}
	int ans = cnt[0] / 2 + (k % 2 == 0 ? cnt[k / 2] / 2 : 0 );
	for (int i = 1; i < k - i; i++) {
		ans += min(cnt[i], cnt[k - i]);

	}
	cout << ans * 2 << endl;
	return 0;
}