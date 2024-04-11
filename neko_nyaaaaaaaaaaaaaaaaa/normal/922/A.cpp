#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int x, y;
	cin >> x >> y;
	if (y == 0) {cout << "No"; return 0;}
	if (x == 0) {
		if (y == 1) {cout << "Yes"; return 0;}
		else {cout << "No"; return 0;}
	}
	if (y == 1) {
		if (x == 0) {cout << "Yes"; return 0;}
		else {cout << "No"; return 0;}
	}
	if (x < y-1) {cout << "No"; return 0;}
	y++;
	x -= y;
	if (x % 2 == 0) {cout << "Yes"; return 0;}
	cout << "No";
	
	
	return 0;
}