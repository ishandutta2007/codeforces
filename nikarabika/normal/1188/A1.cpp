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
	int d[n];
	memset(d, 0, sizeof d);
	for (int i = 1; i< n; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		d[fi]++;
		d[se]++;
	}
	if (find(d, d + n, 2) == d + n)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}