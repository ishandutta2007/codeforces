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
	map<int, int> mp;
	mp[4] = 0;
	mp[8] = 1;
	mp[15] = 2;
	mp[16] = 3;
	mp[23] = 4;
	mp[42] = 5;
	int cnt[6] = {0, 0, 0, 0, 0, 0};
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int id = mp[x];
		if (!id or (id and cnt[id] < cnt[id - 1]))
			cnt[id]++;
		else
			ans++;
	}
	for (int i = 0; i < 6; i++) {
		ans += cnt[i] - cnt[5];
	}
	cout << ans << endl;
	return 0;
}