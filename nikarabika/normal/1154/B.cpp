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
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	if (a[0] == a[n - 1])
		return cout << 0 << endl, 0;
	int ans = 1e5;
	for (int must = -1000; must < +1000; must++) {
		bool good = true;
		int val = 0;
		for (int j = 0; j < n and good; j++)
			if (a[j] - must)
				if (val == 0)
					val = a[j] - must;
				else if (a[j] - must != val and a[j] - must != -val)
					good = false;
		if (good)
			smin(ans, abs(val));
	}
	if (ans == 1e5)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}