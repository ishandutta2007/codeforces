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

const int maxn = 1e5 + 10;
LD aval[maxn],
   bval[maxn];
LL x[maxn],
   y[maxn];
int n;
LL ax, ay, bx, by, tx, ty;
LD ans;

LD getlen(LD x, LD y) {
	return sqrt(x * x + y * y);
}

LD getdis(LD x, LD y, LD xx, LD yy) {
	return getlen(x - xx, y - yy);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> ax >> ay >> bx >> by >> tx >> ty;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		LD dist = getdis(tx, ty, x[i], y[i]);
		ans += dist * 2;
		aval[i] = getdis(ax, ay, x[i], y[i]) - dist;
		bval[i] = getdis(bx, by, x[i], y[i]) - dist;
	}
	LD mina = 0, minb = 0;
	LD cur = 1e18;
	for (int i = 0; i < n; i++) {
		if (aval[i] + minb < cur)
			cur = aval[i] + minb;
		if (bval[i] + mina < cur)
			cur = bval[i] + mina;
		smin(mina, aval[i]);
		smin(minb, bval[i]);
	}
	cout.precision(10);
	cout << fixed << ans + cur << endl;
	return 0;
}