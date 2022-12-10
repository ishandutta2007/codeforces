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
	int eqcnt = 0;
	for (int i = 0; i + 1 < n; i++) {
		if (a[i] == a[i + 1]) {
			eqcnt++;
			if (a[i] == 0 or (i > 0 and a[i - 1] == a[i] - 1))
				return cout << "cslnb" << endl, 0;
		}
	}
	if (eqcnt > 1)
		return cout << "cslnb" << endl, 0;
	bool res = true;
	for (int i = 0; i < n; i++)
		res ^= (a[i] - i) & 1;
	if (res)
		return cout << "cslnb" << endl, 0;
	cout << "sjfnb" << endl;
	return 0;
}