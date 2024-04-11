#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;
//
long long a1, a2, a3, a4;
//
bool exist(int a1, int a2, int a3, int a4) {
	if (abs(a3-a4)<=1 && max(a3, a4) <= min(a1, a2) && a3+a4 != a1+a2 && !(min(a1, a2)>0 && a3==0 && a4==0)) return true;
	return false;
}
bool exist4(int a1, int a2, int a3, int a4) {
	if (!exist(a1, a2, a3, a4)) return false;
	if (a1 < a2 && ((a3 >=1 && a3 <= a1 && a4 <= a3 && a4 != a1))) return true;
	if (a1 >= a2 && ((a3 >= 1 && a3 <= a2 && a4 <= a3))) return true; 
	if (a2 == 0 && a3 == 0 && a4 == 0)  return true;
	return false;
};
//
void write(int a1, int a2, int a3, int a4) {
	if (a1 + a2 > 0) {
		if (exist4(a1, a2, a3, a4)) {
			cout << 4;
			if (exist4(a1-1, a2, a3, a4)) write(a1-1, a2, a3, a4); else
				write(a1-1, a2, a3-1, a4);
		} else {
			if (exist(a1, a2, a3, a4)) {
				cout << 7;
				if (exist4(a1, a2-1, a3, a4-1)) write(a1, a2-1, a3, a4-1); else
					write(a1, a2-1, a3, a4);
			} else {
				cout << -1 << endl;
			}
		}
	}
}
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> a1 >> a2 >> a3 >> a4;
	write(a1, a2, a3, a4);
}