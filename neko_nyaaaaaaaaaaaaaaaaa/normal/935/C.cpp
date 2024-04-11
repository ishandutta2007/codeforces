#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double dist(double x1, double y1, double x2, double y2) {
	double k = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	return k;
}

int main() {
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(12);
	
	double r, x1, y1, x2, y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	double ans1, ans2, ans3;
	if (dist(x1, y1, x2, y2) >= r) {
		cout << x1 << " " << y1 << " " << r; return 0;
	} else if (x1 == x2 && y1 == y2) {
		cout << x1+r/2 << " " << y1 << " " << r/2; return 0;
	} else {
		double d = dist(x1, y1, x2, y2);
		double cosine = (x2 - x1)/d;
		ans3 = (r+d)/2;
		ans1 = x2 - (r+d)*cosine;
		ans1 = (x2 + ans1)/2;
		double sine = (y2 - y1)/d;
		ans2 = y2 - (r+d)*sine;
		ans2 = (y2 + ans2)/2;
		cout << ans1 << " " << ans2 << " " << ans3; 
	}
	
	return 0;
}