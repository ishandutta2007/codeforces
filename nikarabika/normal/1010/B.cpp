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
	int n, m, p[100];
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cout << 1 << endl;
		cin >> p[i];
		if (p[i] == 0)
			return 0;
	}
	int lo = 1,
		hi = m;
	for (int i = 0; true; i = (i + 1) % n) {
		int mid = (lo + hi) / 2;
		cout << mid << endl;
		int v;
		cin >> v;
		v *= p[i];
		if (v == 0)
			return 0;
		if (v == -1)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	return 0;
}