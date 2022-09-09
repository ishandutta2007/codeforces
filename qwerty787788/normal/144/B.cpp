#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

long long xa, ya, xb, yb, a1, a2, a3, a4, x, y, r, n;
long long a_1[2500], a_2[2500], a_3[2500], a_4[2500];
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> a1 >> a2 >> a3 >> a4;
	xa= min(a1, a3);
	xb= max(a1, a3);
	ya= min(a2, a4);
	yb= max(a2, a4);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> r;
		for (long long x_1=xa; x_1 <= xb; x_1++) {
			if ((x-x_1)*(x-x_1)+(y-ya)*(y-ya)<=r*r) a_1[x_1-xa] = 1;
			if ((x-x_1)*(x-x_1)+(y-yb)*(y-yb)<=r*r) a_2[x_1-xa] = 1;
		}
		for (long long y_1=ya+1; y_1 < yb; y_1++) {
			if ((x-xa)*(x-xa)+(y-y_1)*(y-y_1)<=r*r) a_3[y_1-ya-1] = 1;
			if ((x-xb)*(x-xb)+(y-y_1)*(y-y_1)<=r*r) a_4[y_1-ya-1] = 1;
		}
	}
	//
	long long sum = 0;
	for (int i = 0; i < (xb-xa+1); i++) {
		if (a_1[i] == 0) sum++;
		if (a_2[i] == 0) sum++;
	}
	for (int i = 0; i < (yb-ya-1); i++) {
		if (a_3[i] == 0) sum++;
		if (a_4[i] == 0) sum++;
	}
	//
	cout << sum << endl;
}