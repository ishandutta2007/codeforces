#include<iostream>
using namespace std;
int main() {
	int x;
	cin >> x;
	long long kol_vo, st, stop, move;
	for (int i = 0; i < x; i++) {
		long long counter = -1;
		long long min = 0;
		cin >> kol_vo >> st >> stop >> move;
		if (abs(stop - st) % move == 0) {
			cout << abs(stop - st) / move << endl;
		}
		else {
			if ((stop - 1) % move == 0) {
				counter = 0;
				counter += (stop) / move;
				if ((st) % move == 0) {
					counter += (st) / move;
				}
				else {
					counter += (st) / move + 1;
				}
				min = counter;
			}
			if ((kol_vo - stop) % move == 0) {
				counter = 0;
				counter += (kol_vo - stop) / move;
				if ((kol_vo - st) % move == 0) {
					counter += (kol_vo - st) / move;
				}
				else {
					counter += (kol_vo - st) / move + 1;
				}
				if (counter < min) {
					min = counter;
				}
				if (min == 0) {
					min = counter;
				}
			}
			if (min != 0) {
				cout << min << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}
}