#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
//
long long n, k;
double x_1, y_1, x, y, dist;
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n >> k;
	//
	cin >> x_1 >> y_1;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		dist += sqrt((x_1-x)*(x_1-x)+(y_1-y)*(y_1-y));
		x_1 = x;
		y_1 = y;
	}
	//
	cout.precision(8);
	dist *= k;
	dist /= 50;
	cout << dist << endl;
	//
	return 0;
}