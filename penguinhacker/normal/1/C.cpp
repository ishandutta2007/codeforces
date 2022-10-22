#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const double PI=acos(-1), EPS=1e-6;

struct Point {
	double x, y;
	Point operator-(const Point& o) const {
		return {x-o.x, y-o.y};
	}
	double operator*(const Point& o) const {
		return x*o.y-y*o.x;
	}
};
double dot(Point a, Point b) {
	return a.x*b.x+a.y*b.y;
}
double dist(Point a) {
	return sqrt(a.x*a.x+a.y*a.y);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	vector<Point> p(3);
	vector<double> ang;
	for (auto& x : p)
		cin >> x.x >> x.y;
	for (int k=0; k<3; ++k) {
		Point a=p[1]-p[0], b=p[2]-p[0];
		ang.push_back(acos(dot(a, b)/(dist(a)*dist(b))));
		p={p[1], p[2], p[0]};
	}
	//cout << ang[0] << " " << ang[1] << " " << ang[2] << endl;
	for (int i=3; i<=100; ++i) {
		bool ok=1;
		for (int j=0; j<3; ++j) {
			bool b=0;
			for (int k=1; k<i; ++k) {
				if (abs(PI*k/i-ang[j])<EPS) {
					b=1;
					break;
				}
			}
			ok&=b;
		}
		if (ok) {
			//cout << i << " " << abs((p[1]-p[0])*(p[2]-p[0]))/2;
			double d=dist(p[1]-p[2]);
			double s=d*sin(PI/i)/sin(ang[0]);
			double h=s/(2*tan(PI/i));
			cout << s*h*i/2;
			return 0;
		}
	}
	return 0;
}