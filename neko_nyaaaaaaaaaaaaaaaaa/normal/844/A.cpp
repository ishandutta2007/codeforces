#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	
	string s;
	int k;
	cin >> s >> k;
	if (k > s.size()) {cout << "impossible";}
	else {
		vector<int> count(256);
		int dupe = 0;
		for (int i = 0; i < s.size(); i++) {
			if (count[s[i]] == 1) {dupe++;}
			if (count[s[i]] == 0) {count[s[i]] = 1;}
		}
		int x = (s.size() - dupe) - k;
		if (x > 0) {cout << 0;}
		else {cout << abs(x);}
	}
	
	return 0;
}