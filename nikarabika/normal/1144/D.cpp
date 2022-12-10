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
int cnt[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	vector<int> all;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		all.PB(a[i]);
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(all(all), a[i]) - all.begin();
		cnt[a[i]]++;
	}
	int ansval = max_element(cnt, cnt + n) - cnt;
	int ans = n - cnt[ansval];
	int anspos = find(a, a + n, ansval) - a;
	cout << ans << '\n';
	for (int i = anspos - 1; i >= 0; i--)
		if (a[i] > ansval)
			cout << 2 << ' ' << i + 1 << ' ' << i + 2 << '\n';
		else if (a[i] < ansval)
			cout << 1 << ' ' << i + 1 << ' ' << i + 2 << '\n';
	for (int i = anspos + 1; i < n; i++)
		if (a[i] > ansval)
			cout << 2 << ' ' << i + 1 << ' ' << i << '\n';
		else if (a[i] < ansval)
			cout << 1 << ' ' << i + 1 << ' ' << i << '\n';
	return 0;
}