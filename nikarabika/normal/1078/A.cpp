//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<LD, LD> pdd;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

LD a, b, c, ax, ay, bx, by;

LD ABS(LD val) {
	return val < 0 ? -val : val;
}

pdd getx(LD x, LD y) {
	if (b != 0)
		return MP(x, (a * x + c) / -b);
	if (a * x + c == 0)
		return MP(x, y);
	return MP(1e18, 1e18);
}

pdd gety(LD x, LD y) {
	if (a != 0)
		return MP((b * y + c) / -a, y);
	if (b * y + c == 0)
		return MP(x, y);
	return MP(1e18, 1e18);
}

LD dis(pdd A, pdd B) {
//	if (ABS(B.L - 1e18) <= 1) {
//		if (ABS(B.R - 1e18) <= 1)
//			return 2e18;
//		B.R = A.R;
//	}
//	if (ABS(B.R - 1e18) <= 1)
//		B.R = A.R;
	LD dx = A.L - B.L;
	LD dy = A.R - B.R;
	return sqrt(dx * dx + dy * dy);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> a >> b >> c;
	cin >> ax >> ay
		>> bx >> by;
	LD ans = ABS(ax - bx) + ABS(ay - by);
	pdd BX = getx(bx, by),
		BY = gety(bx, by),
		AX = getx(ax, ay),
		AY = gety(ax, ay);
	smin(ans, dis(MP(ax, ay), AX) + dis(MP(bx, by), BX) + dis(AX, BX));
	smin(ans, dis(MP(ax, ay), AX) + dis(MP(bx, by), BY) + dis(AX, BY));
	smin(ans, dis(MP(ax, ay), AY) + dis(MP(bx, by), BX) + dis(AY, BX));
	smin(ans, dis(MP(ax, ay), AY) + dis(MP(bx, by), BY) + dis(AY, BY));
	cout.precision(10);
	cout << fixed << ans << endl;
	return 0;
}