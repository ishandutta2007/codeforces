#include <iostream>
#include <string>

using namespace std;

string days[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main () {
	string A, B;
	cin >> A >> B;
	for (int i = 0; i < 7; i++) {
		if (A == days[i]) {
			if (B == days[i] || B == days[(i + 2) % 7] || B == days[(i + 3) % 7])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
			return 0;
		}
	}
}