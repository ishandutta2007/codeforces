#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


vector<pair<double,double>> v;
#define PII 3.14159265359

int main() {
	double x = 0, y = 0;
	double s;
	for (int i = 0; i < 6; i++) {
		v.push_back({x,y});
		double d;
		cin >> d;
		x += sin(s)*d;
		y += cos(s)*d;
		s += PII/3;
	}
	v.push_back(v[0]);
	double a = 0;
	for (int i = 0; i < 6; i++) {
		a += v[i].first*v[i+1].second-v[i].second*v[i+1].first;
	}
	a = fabs(a);
	double z = sqrt(0.75);
	cout << (int)(a/z+0.5) << "\n";
}