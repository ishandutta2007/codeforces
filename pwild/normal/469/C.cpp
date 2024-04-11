#include <iostream>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)


int main() {

	int n; cin >> n;

	if (n <= 3) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;

		if (n % 2 == 0) {
			FOR(i, 2, n / 2) {
				cout << 2 * i + 2 << " - " << 2 * i + 1 << " = 1" << endl;
				cout << "1 * 1 = 1" << endl;
			}
			cout << "1 * 2 = 2" << endl;
			cout << "2 * 3 = 6" << endl;
			cout << "4 * 6 = 24" << endl;
		}
		else {
			FOR(i, 2, n / 2) {
				cout << 2 * i + 3 << " - " << 2 * i + 2 << " = 1" << endl;
				cout << "1 * 1 = 1" << endl;
			}
			cout << "3 * 4 = 12" << endl;
			cout << "1 + 5 = 6" << endl;
			cout << "6 * 2 = 12" << endl;
			cout << "12 + 12 = 24" << endl;
		}


	}



}