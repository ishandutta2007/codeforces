#include <iostream>
#include <math.h>

using namespace std;

int n;

double dis(double a, double b, double c, double x, double y) {
	double v = a * x + b * y + c;
	if(v < 0) {
		v = -v;
	}
	return v / sqrt(a * a + b * b);
}
int main() {
	double x1, y1, x2, y2;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> n;
	int cnt = 0;
	for(int i = 0;i < n;i++) {
		double a, b, c1;
		cin >> a >> b >> c1;
		double c2 = -a * x1 - b * y1;
		int f1 = (dis(a, b, c1, x2, y2) < dis(a, b, c2, x2, y2));
		double c3 = -a * x2 - b * y2;
		int f2 = (dis(a, b, c1, x1, y1) < dis(a, b, c3, x1, y1));
		cnt += f1 && f2;
	}
	cout << cnt << endl;
	return 0;
}