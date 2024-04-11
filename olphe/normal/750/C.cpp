#include "iostream"
#include "iomanip"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"

using namespace std;

int N;
int c[200000], d[200000];
int l, r;

int main() {
	cin >> N;
	cin >> c[0] >> d[0];
	if (d[0] == 1) {
		l = 1900;
		r = INT_MAX;
	}
	else {
		l = INT_MIN;
		r = 1899;
	}
	if (l != INT_MIN) {
		l += c[0];
	}
	if (r != INT_MAX) {
		r += c[0];
	}
	if (r < l) {
		cout << "Impossible\n";
		return 0;
	}
	//cout << l << " " << r << "\n";
	for (int i = 1; i < N; i++) {
		cin >> c[i] >> d[i];
		if (d[i] == 1) {
			l = max(1900,l)+c[i];
			if (r != INT_MAX) {
				r += c[i];
			}
		}
		else {
			r = min(1899,r)+c[i];
			if (l != INT_MIN) {
				l += c[i];
			}
		}
		if (r < l) {
			cout << "Impossible\n";
			return 0;
		}
	//	cout << l << " " << r << "\n";
	}
	if (r == INT_MAX) {
		cout << "Infinity\n";
		return 0;
	}
	cout << r << "\n";
	return 0;
}