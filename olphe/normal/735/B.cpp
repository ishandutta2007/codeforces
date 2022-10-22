#include "iostream"
#include "iomanip"
#include "math.h"
#include "functional"
#include "algorithm"
#include "set"
using namespace std;

multiset<double,greater<double>> wealth;
double N, A, B;
double box;
int num;
double ans;

int main() {
	cin >> N >> A >> B;
	for (int i = 0; i < N; i++) {
		cin >> box;
		wealth.insert(box);
	}
	if (A > B) {
		box = A;
		A = B;
		B = box;
	}
	box = 0;
	for (auto i = wealth.begin(); i!=wealth.end(); ++i) {
		num++;
		box += (*i);
		if (num == A) {
			ans = box / A;
			box = 0;
		}
		if (num == A + B) {
			ans += box / B;
		}
	}
	cout << setprecision(15) << ans << "\n";
	return 0;
}