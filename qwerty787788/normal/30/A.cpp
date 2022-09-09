#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>;
using namespace std;



double a, b, n;

//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> a >> b >> n;
	double answ = 0;
	if (a == 0) {
		if (b== 0) {
			cout << 5 << endl;
			return 0;
		} else {
			cout << "No solution" << endl;
			return 0;
		}
	}
	if (b/a > 0)
		answ = pow((b/a), 1/n); else 
		answ = -pow((-b/a), 1/n);
	if (abs(answ-ceil(answ)) < 0.0001) cout << ceil(answ)<< endl; else cout << "No solution" << endl;
	//
	return 0;
}