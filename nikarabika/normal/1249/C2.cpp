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

int solve() {
	LL n;
	cin >> n;
	LL tmp = n;
	vector<int> vec;
	while (tmp)
		vec.PB(tmp % 3), tmp /= 3;
	vec.PB(0);
	int last = -1;
	for (int i = 0; i < sz(vec); i++)
		if (vec[i] == 2)
			last = i;
	if (last == -1)
		return cout << n << '\n', 0;
	int car = 0;
	for (int i = last; i < sz(vec); i++)
		if (vec[i])
			vec[i] = 0;
		else {
			vec[i] = 1;
			break;
		}
	for (int i = 0; i < last; i++)
		vec[i] = 0;
	LL ans = 0,
	   cur = 1;
	for (int i = 0; i < sz(vec); i++, cur *= 3)
		if (vec[i])
			ans += cur;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}