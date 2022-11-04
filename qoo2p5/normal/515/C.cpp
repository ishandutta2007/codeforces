#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
string s;
int prime[4] = {2, 3, 5, 7};
int number[10];

int factorial(int x) {
	int p = 1;
	for(int i = 2; i <= x; i++) {
		p *= i;
	}

	return p;
}

int main() {
	cin >> n;
	cin >> s;

	for(int i = 0; i < n; i++) {
		int digit = s[i] - '0';

		digit = factorial(digit);

		while(digit != 1) {
			for(int i = 0; i < 4; i++) {
				if(digit % prime[i] == 0) {
					digit /= prime[i];
					number[prime[i]]++;
				}
			}
		}
	}


	for(int i = 7; i >= 2; i--) {
		while(number[i]) {
			cout << i;

			for(int j = i; j >= 2; j--) {
				int x = j;

				while(x != 1) {
					for(int k = 0; k < 4; k++) {
						if(x % prime[k] == 0) {
							x /= prime[k];
							number[prime[k]]--;
						}
					}
				}
			}
		}
	}

	cout << endl;

	return 0;
}