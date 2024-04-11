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
	int n, m;
	cin >> n >> m;
	int cnt[m][5];
	int a[m];
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			cnt[j][s[j] - 'A']++;
	}
	LL ans = 0;
	for (int i = 0; i < m; i++) {
		LL x;
		cin >> x;
		ans += x * *max_element(cnt[i], cnt[i] + 5);
	}
	cout << ans << endl;
	return 0;
}