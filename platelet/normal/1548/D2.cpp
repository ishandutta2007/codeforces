#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 6005;

int n, x[N], y[N], c[N][4][4][4];

int main() {
	cin >> n;
	rep(i, 1, n) scanf("%d%d", &x[i], &y[i]);
	rep(i, 1, n) rep(j, 1, n) c[i][x[j] & 3][y[j] & 3][__gcd(abs(x[i] - x[j]), abs(y[i] - y[j])) & 3]++;
	ll as[2] = {};
	rep(i, 1, n) {
		int x0 = x[i] & 3, y0 = y[i] & 3;
		rep(x1, 0, 3) rep(y1, 0, 3) rep(z1, 0, 3) {
			auto chk = [&](int x, int y, int z) { return x == x0 && y == y0 && !z; };
			int a = c[i][x1][y1][z1] - chk(x1, y1, z1);
			rep(x2, 0, 3) if(x1 % 2 == x2 % 2) rep(y2, 0, 3) if(y1 % 2 == y2 % 2) rep(z2, 0, 3) if(z1 % 2 == z2 % 2) {
				int S = x0 * y1 + x1 * y2 + x2 * y0 - x1 * y0 - x2 * y1 - x0 * y2 & 3;
				if(S % 2 || S ^ (z1 + z2 + (x1 == x2 && y1 == y2 ? 0 : 2)) % 4) continue;
				as[z1 & 1] += a * (c[i][x2][y2][z2] - (x1 == x2 && y1 == y2 && z1 == z2) - chk(x2, y2, z2));
			}
		}
	}
	cout << as[0] / 6 + as[1] / 2;
	return 0;
}