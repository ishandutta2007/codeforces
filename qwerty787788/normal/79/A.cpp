#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int x, y, move = 0;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> x >> y;
	while (true) {
		if (move == 0) {
			if (x >=2 && y >= 2) {
				x -= 2;
				y -= 2;
			} else 
			if (x >= 1 && y >= 12) {
				x -= 1;
				y -= 12;
			} else 
			if (y >= 22) {
				y -= 22;
			} else {
				cout << "Hanako";
				return 0;
			}
		} else {
			if (y >= 22) {
				y -= 22;
			} else 
			if (x >= 1 && y >= 12) {
				x -= 1;
				y -= 12;
			} else 
			if (x >= 2 && y >= 2) {
				y -= 2;
				x -= 2;
			} else {
				cout << "Ciel";
				return 0;
			}
		}
		move = 1-move;
	}
	//
	return 0;
};