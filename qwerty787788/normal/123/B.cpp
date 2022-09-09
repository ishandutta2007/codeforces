#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>

using namespace std;
//
int n;
double a, b, x_1, y_1, x_2, y_2;
double x1_new, y1_new, x2_new, y2_new;

//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> a >> b >> x_1 >> y_1 >> x_2 >> y_2;
	y1_new = (-x_1/2+y_1/2)/b;
	x1_new = (x_1/2+y_1/2)/a;
	//
	y2_new = (-x_2/2+y_2/2)/b;
	x2_new = (x_2/2+y_2/2)/a;
	int dx = (int)(abs(ceil(x2_new)-ceil(x1_new)));
	int dy = (int)(abs(ceil(y2_new)-ceil(y1_new)));
	int answ = max(dx, dy);
	cout << answ << endl;
	//
	return 0;
}