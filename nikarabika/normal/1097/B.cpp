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
	for (int i = 0; i< n; i++)
		cin >> a[i];
	for (int mask = 0; mask < (1 << n); mask++) {
		int sum = 0;
		for (int i = 0; i < n; i++)
			if (((mask >> i) & 1))
				sum += a[i];
			else
				sum += 360 - a[i];
		sum %= 360;
		if (sum == 0) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}