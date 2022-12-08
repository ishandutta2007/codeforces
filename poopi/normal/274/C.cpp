										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>
#define EPS 1e-9
#define PI acos(-1.)

bool eq(double a, double b){
	return fabs(a - b) < EPS;
}

bool ls(double a, double b){
	return a + EPS < b;
}

bool gr(double a, double b){
	return a - EPS > b;
}

bool circleThroughPoints(double x1, double y1, double x2, double y2, double x3, double y3,
						 double &x, double &y, double &r){
	double d = 2 * (y1 * x3 + y2 * x1 - y2 * x3 - y1 * x2 - y3 * x1 + y3 * x2);
	if (eq(d, 0))
		return false;
	x = (y2 * x1 * x1 - y3 * x1 * x1 - y2 * y2 * y1 + y3 * y3 * y1 +
	     x2 * x2 * y3 + y1 * y1 * y2 + x3 * x3 * y1 - y3 * y3 * y2 -
	     x3 * x3 * y2 - x2 * x2 * y1 + y2 * y2 * y3 - y1 * y1 * y3) / d;
	y = (x1 * x1 * x3 + y1 * y1 * x3 + x2 * x2 * x1 - x2 * x2 * x3 +
	     y2 * y2 * x1 - y2 * y2 * x3 - x1 * x1 * x2 - y1 * y1 * x2 -
	     x3 * x3 * x1 + x3 * x3 * x2 - y3 * y3 * x1 + y3 * y3 * x2) / d;
	r = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
	return true;
}

int n;
double x[110], y[110];
vector <double> v;

double dist(int idx, double a, double b){
	double dx = x[idx] - a;
	double dy = y[idx] - b;
	return sqrt(dx * dx + dy * dy);
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	double a, b, r;
	bool flag = false;
	double res = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			for(int k = j + 1; k < n; k++){
				if(circleThroughPoints(x[i], y[i], x[j], y[j], x[k], y[k], a, b, r)){
					//cout << i << ' ' << j << ' ' << k << ' ' << a << ' ' << b << ' ' << r << endl;
					bool gd = true;
					v.clear();
					for(int l = 0; l < n; l++){
						if(ls(dist(l, a, b), r))
							gd = false;
						if(eq(dist(l, a, b), r)){
							v.push_back(atan2(y[l] - b, x[l] - a));
							//cout << l << ' ' << v.back() << ' ' << y[l] - a << ' ' << x[l] - b << endl;
						}
					}
					//cout << gd << endl;
					sort(v.begin(), v.end());
					v.push_back(v[0] + 2 * PI);
					for(int i = 1; i < v.size(); i++){
						double t = v[i] - v[i - 1];
						//cout << v[i] << ' ' << v[i - 1] << ' ' << t << ' ' << PI << endl;
						if(!ls(t, PI))
							gd = false;
					}
					//cout << gd << endl;
					if(gd){
						res = max(res, r);
						flag = true;
					}
				}
			}
		}
	}
	if(flag){
		cout.precision(6);
		cout.setf(ios::fixed | ios::showpoint);
		cout << res << endl;
	}
	else cout << -1 << endl;
	return 0;
}