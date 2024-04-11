#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"

using namespace std;
int x[4], y[4];

int main() {
	for (int i = 1; i < 4; i++) {
		cin >> x[i] >> y[i];
	}
	cout << "3\n";
	cout << x[3] + (x[2] - x[1]) << " " << y[3] + (y[2] - y[1]) << "\n";
	cout << x[2] + (x[1] - x[3]) << " " << y[2] + (y[1] - y[3]) << "\n";
	cout << x[1] + (x[3] - x[2]) << " " << y[1] + (y[3] - y[2]) << "\n";
	return 0;
}