#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	long n;
	cin >> n;
	string s;
	vector<long> a(7);
	for (long i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < 7; j++) {
			if (s[j] == '1') {a[j]++;}
		}
	}
	long max = 0;
	for (int i = 0; i < 7; i++) {
		if (a[i] > max) {max = a[i];}
	}
	cout << max;
	
	
	return 0;
}