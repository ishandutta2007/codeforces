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

const int maxn = 2e5 + 100;
LL a[maxn],
   hp, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> hp >> n;
	LL sum = 0,
	   mn = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		smin(mn, sum);
	}
	if (hp + mn > 0 and sum >= 0)
		return cout << -1 << endl, 0;
	sum *= -1;
	mn *= -1;
	LL rounds = (hp - mn <= 0 or sum == 0) ? 0 : ((hp - mn - 1) / sum + 1);
	cerr << sum << ' ' << mn << ' ' << rounds << endl;
	
	hp -= rounds * sum;
	for (int i = 0; i < n; i++) {
		hp += a[i];
		if (hp <= 0)
			return cout << rounds * n + i + 1 << endl, 0;
	}

	return 0;
}