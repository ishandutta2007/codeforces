#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, x1, y1, x2, y2;
double lb=0, rb=69696969;

double get(int d, double v) { // get from p to t
	return d<=0?0.0:d/v;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> x1 >> y1 >> x2 >> y2;
	for (int i=0; i<n; ++i) {
		int x, y, vx, vy;
		cin >> x >> y >> vx >> vy;
		if (vx==0) {
			if (x<=x1||x>=x2) {
				cout << -1;
				return 0;
			}
		} else {
			lb=max(lb, vx>0?get(x1-x, vx):get(x-x2, -vx));
			rb=min(rb, vx>0?get(x2-x, vx):get(x-x1, -vx));
		}
		if (vy==0) {
			if (y<=y1||y>=y2) {
				cout << -1;
				return 0;
			}
		} else {
			lb=max(lb, vy>0?get(y1-y, vy):get(y-y2, -vy));
			rb=min(rb, vy>0?get(y2-y, vy):get(y-y1, -vy));
		}
		//cout << lb << " " << rb << endl;
	}
	if (lb>=rb) {
		cout << -1;
		return 0;
	}
	cout << fixed << setprecision(6) << lb;
	return 0;
}