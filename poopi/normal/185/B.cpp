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

double s;
double a, b, c;

double val(double x, double y, double z){
	double l1 = (x < 1e-200 ? -200 : log(x));
	double l2 = (y < 1e-200 ? -200 : log(y));
	double l3 = (z < 1e-200 ? -200 : log(z));
	return a * l1 + b * l2 + c * l3;
}

double calc(double x, double &y){
	double ly = 0, ry = s - x;
	for(int i = 0; i < 300; i++){
		double y1 = (2 * ly + ry) / 3;
		double y2 = (ly + 2 * ry) / 3;
		double m1 = val(x, y1, s - x - y1);
		double m2 = val(x, y2, s - x - y2);
		if(m1 < m2)
			ly = y1;
		else ry = y2;
	}
	y = ly;
	return val(x, y, s - x - y);
}

string toS(int64 a){
	string ret = "";
	if(a == 0)
		return "0";
	while(a){
		ret = (char)(a % 10 + '0') + ret;
		a /= 10;
	}
	return ret;
}

string f(double x){
	int64 a = x;
	int64 b = 1000000000000LL * (x - a);
	string res = toS(a) + ".";
	string k = "";
	for(int i = 0; i < 12; i++){
		k = (char)(b % 10 + '0') + k;
		b /= 10;
	}
	return res + k;
}

int main(){
	cin >> s >> a >> b >> c;
	double y;
	double lx = 0, rx = s;
	for(int i = 0; i < 300; i++){
		double x1 = (2 * lx + rx) / 3;
		double x2 = (lx + 2 * rx) / 3;
		double m1 = calc(x1, y);
		double m2 = calc(x2, y);
		if(m1 < m2)
			lx = x1;
		else rx = x2;
	}
	calc(lx, y);
	double z = s - lx - y;
	cout.precision(7);
	cout.setf(ios::fixed | ios::showpoint);
	cout << f(lx) << ' ' << f(y) << ' ' << f(s - lx - y) << endl;
	return 0;
}