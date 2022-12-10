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

const int n = 1e6;
int a[n];
bool mark[n + 1];

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int mn = 0,
		sum = 0;
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		sum += x;
		smin(mn, sum);
		a[i] = x;
	}
	a[0] = 1 + -mn;
	if (a[0] <= 0 or a[0] > n or mark[a[0]])
		return cout << -1 << endl, 0;
	mark[a[0]] = true;
	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1];
		if (a[i] <= 0 or a[i] > n or mark[a[i]])
			return cout << -1 << endl, 0;
		mark[a[i]] = true;
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;

	return 0;
}