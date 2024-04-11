#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

const int MN = 100000;
const int K = 200;

int x[MN];
int y[MN];

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", x + i, y + i);
	double on_line_exp = 0;
	double area_exp = 0; 
	double tmp;
	double p2;

	//compute area_exp
	int uptoo = min(n, K);
	for (int i = 0; i < n; i++) {
		double tmp = 0;
		p2 = 0.25;
		for (int j = 1; j < uptoo; j++) {
			int ni = (i + j) % n;
			tmp += ((double)x[i] * y[ni] - (double)y[i] * x[ni])*p2;
			p2 /= 2;
		}
		area_exp += tmp;
	}
	
	area_exp /= 2;

	double small_p2 = 1;
	for (int i = 0; i < n; i++) small_p2 /= 2;

	//compute on_line_exp
	p2 = 0.25;
	for (int j = 1; j < uptoo; j++) {
		double tmp2 = 0;
		for (int i = 0; i < n; i++) {
			int ni = (i + j) % n;
			tmp2 += (p2 - small_p2)*gcd(abs(x[i] - x[ni]), abs(y[i] - y[ni])) + small_p2;
		}
		on_line_exp += tmp2;
		p2 /= 2;
	}

	double exp = area_exp - on_line_exp / 2 + 1;
	exp -= (small_p2)*(n + 1);
	if (n < 1000) {
		int bad = n*(n - 1) / 2 + n + 1;
		double badprob = bad * small_p2;
		exp = exp/(1 - badprob);
	}
	cout << setprecision(15) << exp;
}