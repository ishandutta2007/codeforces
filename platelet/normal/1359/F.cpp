#include <bits/stdc++.h>

using namespace std;

const int N = 2.5e4 + 5;

int n, x[N], y[N], dx[N], dy[N], s[N];
double len[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> dx[i] >> dy[i] >> s[i];
		len[i] = hypot(dx[i], dy[i]);
	}
	bool ok = 0;
	double ans1 = 1e20, ans2 = 1e20;
	for(int i = 0; i < n; i++) for(int j = 0; j < i; j++) {
		int xx = x[i] - x[j], yy = y[i] - y[j];
		int c = dx[i] * dy[j] - dy[i] * dx[j];
		int a = dx[j] * yy - dy[j] * xx;
		if(c) {
			int b = xx * dy[i] - yy * dx[i];
			if((!a || (a ^ c) >= 0) && (!b || (b ^ -c) >= 0)) {
				ok = 1;
				ans1 = min(ans1, max(a * len[i] / (c * s[i]), b * len[j] / (-c * s[j])));
			}
		} else if(!a) {
			int sp = (dx[i] ^ -xx) >= 0 ? s[i] : 0;
			sp += (dx[j] ^ xx) >= 0 ? s[j] : 0;
			if(sp) ok = 1, ans2 = min(ans2, double(1LL * xx * xx + 1LL * yy * yy) / double(1LL * sp * sp));
		}
	}
	if(ok) printf("%.10lf\n", min(ans1, sqrt(ans2)));
	else cout << "No show :(";
}