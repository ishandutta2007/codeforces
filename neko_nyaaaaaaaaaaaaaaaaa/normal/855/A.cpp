#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	
	long long n;
	cin >> n;
	string tmp;
	vector<string> v;
	for (long long i = 0; i < n; i++) {
		cin >> tmp;
		long long j = 0;
		bool com = false;
		while (j < v.size()) {
			if (v[j] == tmp) {
				com = true;
				break;
			}
			j++;
		}
		if (com) {cout << "YES" << endl;}
		else {
			v.push_back(tmp);
			cout << "NO" << endl;
		}
	}
	
	return 0;
}