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

const int maxn = 1e3 + 10;
LD a[maxn],
   b[maxn],
   m;
int n;

LD get(LD w, LD f) {
	return w / f;
}

bool check(LD val) {
	for (int i = 0; i < n; i++) {
		val -= get(m + val, a[i]);
		if (val < 0) return false;
		val -= get(m + val, b[(i + 1) % n]);
		if (val < 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	LD lo = 0,
	   hi = 1e12;
	for (int _ = 0; _ < 200; _++) {
		LD mid = (lo + hi) / 2;
		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}
	if (hi < 5e9)
		cout << fixed << setprecision(10) << hi << '\n';
	else
		cout << -1 << endl;
	return 0;
}