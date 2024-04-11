#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
#define int long long

void solve() {
	int n, L;
	cin >> n >> L;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	double l = 0, r = L; int ite = 90;
	while (abs(l-r) > eps && ite > 0) {
		ite--;
		double mid = (l + r)/2;
		//cout << fixed << setprecision(9) << mid << endl;

		double lp = 0; int speed = 1;
		double tleft = mid;
		for (int i = 0; i < n; i++) {
			double dist = abs(a[i] - lp);
			double tme = dist/speed;

			if (tleft < tme) {
				lp += tleft*speed;
				tleft = 0;
				break;
			} else {
				lp += dist;
				tleft -= tme;
				speed++;
			}
		}
		if (tleft > 0) {
			lp += speed*tleft;
		}

		double rp = L; speed = 1;
		tleft = mid;
		for (int i = n-1; i >= 0; i--) {
			double dist = abs(a[i] - rp);
			double tme = dist/speed;

			if (tleft < tme) {
				rp -= tleft*speed;
				tleft = 0;
				break;
			} else {
				rp -= dist;
				tleft -= tme;
				speed++;
			}
		}
		if (tleft > 0) {
			rp -= speed*tleft;
		}

		if (lp > rp) {
			r = mid;
		} else {
			l = mid;
		}
	}

	cout << fixed << setprecision(9) << l << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}