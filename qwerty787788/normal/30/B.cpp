#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>;
using namespace std;


int a1, b1, c1, a2, b2, c2, a3, b3, c3;
string s1, s2;
//
bool ok(int a1, int b1, int c1, int a2, int b2, int c2) {
	if ((b2 > 12) || (b2 == 0)) return false;
	if ((b2 == 1) || (b2 == 3) || (b2 == 5) || (b2 == 7) || (b2 == 8) || (b2 == 10) || (b2 ==12)) {
		if (a2 > 31) return false;
	} else {
		if (b2 == 2) {
			if (c2 % 4 == 0) {
				if (a2 > 29) return false;
			} else {
				if (a2 > 28) return false;
			}
		} else {
			if (a2 > 30) return false;
		}
	}
	if (c1-c2 > 18) {
		return true;
	} else {
		if (c1-c2 == 18) {
			if (b1 > b2) {
				return true;
			} else {
				if (b1 == b2) {	
					if (a1 >= a2) return true;
				} else {
					return false;
				}
			}
		} else {
			return false;
		}
	}
	return false;
}
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> s1;
	cin >> s2;
	a1 = (int)(s1[0]-'0')*10+(int)(s1[1]-'0');
	b1 = (int)(s1[3]-'0')*10+(int)(s1[4]-'0');
	c1 = (int)(s1[6]-'0')*10+(int)(s1[7]-'0');
	//
	a2 = (int)(s2[0]-'0')*10+(int)(s2[1]-'0');
	b2 = (int)(s2[3]-'0')*10+(int)(s2[4]-'0');
	c2 = (int)(s2[6]-'0')*10+(int)(s2[7]-'0');
	//
	a3 = max(max(a2, b2), c2);
	c3 = min(min(a2, b2), c2);
	b3 = b2+a2+c2-a3-c3;
	//
	if (ok(a1, b1, c1, a2, b2, c2) || 
		ok(a1, b1, c1, a2, c2, b2) ||
		ok(a1, b1, c1, b2, a2, c2) ||
		ok(a1, b1, c1, b2, c2, a2) ||
		ok(a1, b1, c1, c2, a2, b2) ||
		ok(a1, b1, c1, c2, b2, a2)) cout << "YES" << endl; else cout << "NO" << endl;
	//
	return 0;
}