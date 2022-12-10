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
	int n, maxx = 0, maxy = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char ty;
		int x, y;
		cin >> ty >> x >> y;
		if (x > y) swap(x, y);
		if (ty == '+')
			smax(maxx, x), smax(maxy, y);
		else
			cout << (x >= maxx and y >= maxy ? "YES\n" : "NO\n");
	}
	return 0;
}