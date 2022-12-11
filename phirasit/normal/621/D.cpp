#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double a[20];
double x, y, z;

double first(int idx) {
	if(1 <= idx and idx <= 4) return log(x);
	if(5 <= idx and idx <= 8) return log(y);
	if(9 <= idx and idx <= 12) return log(z);
	return 0.0;
}
double second(int idx) {
	switch(idx) {
		case 1: return z * log(y);
		case 2: return y * log(z);
		case 3: return log(y) + log(z);
		case 4: return log(z) + log(y);
		case 5: return z * log(x);
		case 6: return x * log(z);
		case 7: return log(x) + log(z);
		case 8: return log(z) + log(x);
		case 9: return y * log(x);
		case 10: return x * log(y);
		case 11: return log(x) + log(y);
		case 12: return log(y) + log(x);
	}
}
int cmp(int idx1, int idx2) {
	double fs1 = first(idx1), fs2 = first(idx2);
	if(fs1 == 0 or fs2 == 0) {
		return fs1 < fs2;
	}
	if((fs1 < 0) ^ (fs2 < 0)) {
		return fs1 < fs2;
	}
	if(fs1 < 0 and fs2 < 0) {
		return second(idx1) + log(-fs1) - (second(idx2) + log(-fs2)) > 1e-12;
	}else {
		return second(idx1) + log(fs1) - (second(idx2) + log(fs2)) < -1e-12;
	}
}
int main() {
	
	cin >> x >> y >> z;

	int ans = 1;
	for(int i = 2;i <= 12;i++) {
		if(cmp(ans, i)) {
			ans = i;
		}
	}
	
	switch(ans) {
		case 1: cout << "x^y^z" << endl; break;
		case 2: cout << "x^z^y" << endl; break;
		case 3: cout << "(x^y)^z" << endl; break;
		case 4: cout << "(x^z)^y" << endl; break;
		case 5: cout << "y^x^z" << endl; break;
		case 6: cout << "y^z^x" << endl; break;
		case 7: cout << "(y^x)^z" << endl; break;
		case 8: cout << "(y^z)^x" << endl; break;
		case 9: cout << "z^x^y" << endl; break;
		case 10: cout << "z^y^x" << endl; break;
		case 11: cout << "(z^x)^y" << endl; break;
		case 12: cout << "(z^y)^x" << endl; break;
	}

  return 0;
}