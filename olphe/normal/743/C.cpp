#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "math.h"
using namespace std;

int a, b, c;
int n;

int main() {
	cin >> n;
	if (n == 1) {
		cout << "-1\n";
		return 0;
	}
	else {
		a = n;
		b = n + 1;
		c = a*b;
	}
	cout << a << " " << b << " " << c << "\n";
	return 0;

}