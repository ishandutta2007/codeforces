#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265358979

double getAng(double x, double y) {
	double ang = atan2(y,x)*180/PI;
	if (ang<0) ang+=360;
	return ang;
}

int n;
double mx, a[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(numeric_limits<double>::max_digits10);

	cin >> n;
	for (int i=0, x, y; i<n; ++i) {
		cin >> x >> y;
		a[i]=getAng(x,y);
	}
	sort(a, a+n);

	mx=a[0]+360-a[n-1];
	for (int i=1; i<n; ++i)
		mx=max(mx, a[i]-a[i-1]);
	cout << 360-mx;
	return 0;
}