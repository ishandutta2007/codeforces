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
	bool a[n],
		b[m];
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			a[i] ^= x;
			b[j] ^= x;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			a[i] ^= x;
			b[j] ^= x;
		}
	for (int i = 0; i < n; i++)
		if (a[i])
			return cout << "No" << endl, 0;
	for (int i = 0; i < m; i++)
		if (b[i])
			return cout << "No" << endl, 0;
	return cout << "Yes" << endl, 0;
	return 0;
}