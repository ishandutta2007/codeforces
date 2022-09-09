#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int n, m;
int a[50][50];
int a1, b1, c1;
//
int x[50];
int y[50];
int answ = 0;
//
int sum_x(int x1, int x2) {
	int s = 0;
	for (int x11 = x1; x11 < x2; x11++) 
		s+= x[x11];
	return s;
}
int sum_y(int x1, int x2) {
	int s = 0;
	for (int x11 = x1; x11 < x2; x11++) 
		s+= y[x11];
	return s;
}
//
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//
	cin >> n >> m;
	//
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			cin >> a[i][j];
	//
	cin >> a1 >> b1 >> c1;
	//
	for (int i = 0; i < n; i++) {
		int s = 0;
		for (int j =0 ; j < m; j ++) {
			s+= a[i][j];
		}
		x[i] = s;
	}
	for (int i = 0; i < m; i++) {
		int s = 0;
		for (int j =0 ; j < n; j ++) {
			s+= a[j][i];
		}
		y[i] = s;
	}
	//
	answ = 0;
	for (int x1 = 1; x1 < n; x1++) {
		for (int x2 = x1+1; x2 < n; x2++) {
			int s1 = sum_x(0, x1);
			int s2 = sum_x(x1, x2);
			int s3 = sum_x(x2, n);
			int ok = false;
			if (s1 == a1) {
				if (s2 == b1) {
					if (s3 == c1) ok = true;
				} else {
					if (s2 == c1) {
						if (s3 == b1) ok = true;
					}
				}
			} else {
				if (s1 == b1) {
					if (s2 == a1) {
						if (s3 == c1) ok = true;
					} else {
						if (s2 == c1) {
							if (s3 == a1) ok = true;
						}
					}
				} else {
					if (s1 == c1) {
						if (s2 == a1) {
							if (s3 == b1) ok = true;
						} else {
							if (s2 == b1) {	
								if (s3 == a1) ok = true;
							}
						}
					}
				}
			}
			if (ok) answ++;
		}
	}
	for (int x1 = 1; x1 < m; x1++) {
		for (int x2 = x1+1; x2 < m; x2++) {
			int s1 = sum_y(0, x1);
			int s2 = sum_y(x1, x2);
			int s3 = sum_y(x2, m);
			int ok = false;
			if (s1 == a1) {
				if (s2 == b1) {
					if (s3 == c1) ok = true;
				} else {
					if (s2 == c1) {
						if (s3 == b1) ok = true;
					}
				}
			} else {
				if (s1 == b1) {
					if (s2 == a1) {
						if (s3 == c1) ok = true;
					} else {
						if (s2 == c1) {
							if (s3 == a1) ok = true;
						}
					}
				} else {
					if (s1 == c1) {
						if (s2 == a1) {
							if (s3 == b1) ok = true;
						} else {
							if (s2 == b1) {	
								if (s3 == a1) ok = true;
							}
						}
					}
				}
			}
			if (ok) answ++;
		}
	}

	//
	cout << answ<< endl;
	//
	return 0;
}