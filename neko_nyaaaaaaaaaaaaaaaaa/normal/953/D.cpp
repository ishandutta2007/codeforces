#include <bits/stdc++.h>
using namespace std;

string a[6];

void print(int s, int b) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
		      if (s == i && b == j) {printf("P");}
		      else {printf("%c", a[i][j]);}
		}
		printf("\n");
	}
}

int main() {
	int s1, s2;
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	bool flag = 0;
	for (int j = 3; j < 5; j++) {
		for (int i = 0; i < 2; i++) {
			if (a[i][j] == '.') {s1 = i; s2 = j; flag = 1; break;}
		}	
		if (flag) break;
	}
	if (flag) {print(s1, s2); return 0;}
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 2; i++) {
			if (a[i][j] == '.') {s1 = i; s2 = j; flag = 1; break;}
		}	
		if (flag) break;
	}
	if (flag) {print(s1, s2); return 0;}
	for (int j = 3; j < 5; j++) {
		for (int i = 2; i < 4; i++) {
			if (a[i][j] == '.') {s1 = i; s2 = j; flag = 1; break;}
		}	
		if (flag) break;
	}
	if (flag) {print(s1, s2); return 0;}
	for (int j = 6; j < 8; j++) {
		for (int i = 0; i < 2; i++) {
			if (a[i][j] == '.') {s1 = i; s2 = j; flag = 1; break;}
		}	
		if (flag) break;
	}
	if (flag) {print(s1, s2); return 0;}
	for (int j = 0; j < 2; j++) {
		for (int i = 2; i < 4; i++) {
			if (a[i][j] == '.') {s1 = i; s2 = j; flag = 1; break;}
		}	
		if (flag) break;
	}
	if (flag) {print(s1, s2); return 0;}
	for (int j = 6; j < 8; j++) {
		for (int i = 2; i < 4; i++) {
			if (a[i][j] == '.') {s1 = i; s2 = j; flag = 1; break;}
		}	
		if (flag) break;
	}
	if (flag) {print(s1, s2); return 0;}
	for (int j = 3; j < 5; j++) {
		for (int i = 4; i < 6; i++) {
			if (a[i][j] == '.') {s1 = i; s2 = j; flag = 1; break;}
		}	
		if (flag) break;
	}
	if (flag) {print(s1, s2); return 0;}
	for (int j = 0; j < 2; j++) {
		for (int i = 4; i < 6; i++) {
			if (a[i][j] == '.') {s1 = i; s2 = j; flag = 1; break;}
		}	
		if (flag) break;
	}
	if (flag) {print(s1, s2); return 0;}
	for (int j = 6; j < 8; j++) {
		for (int i = 4; i < 6; i++) {
			if (a[i][j] == '.') {s1 = i; s2 = j; flag = 1; break;}
		}	
		if (flag) break;
	}
	if (flag) {print(s1, s2); return 0;}
	
	return 0;
}