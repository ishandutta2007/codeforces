#include <iostream>
#include <vector>
#include <string>
using namespace std;

string ans;

bool ask(int x) {
	cout << x << endl, fflush(stdout), cout.flush(), cin >> ans;
	if (ans == "yes") return true;
	return false;
}

int main() {
	vector<int> primes = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53 };
	ios::sync_with_stdio(0);
	for (int i = 0; i < 4; i++) {
		if (ask(primes[i])) {
			for (int j = 0; primes[i] * primes[j] <= 100; j++)
				if (ask(primes[i] * primes[j])) {
					cout << "composite" << endl, fflush(stdout), cout.flush();
					return 0;
				}
			cout << "prime" << endl, fflush(stdout), cout.flush();
			return 0;
		}
	}
	cout << "prime" << endl, fflush(stdout), cout.flush();
	return 0;
}