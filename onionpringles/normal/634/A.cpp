#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <complex>
#include <tuple>

#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const double pi = 3.1415926535897932384626433832795;
const int mod = 1000000007;

vector<int> a;
vector<int> b;

int x[200000];
int y[200000];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n); int xi; int yi;
	for (int i = 0; i < n; i++) {
		ni(x[i]);
		if (x[i] == 1) xi = i;
	}
	for (int i = 0; i < n; i++) {
		ni(y[i]);
		if (y[i] == 1)yi = i;
	}
	for (int j = xi; ; ) {
		if(x[j])a.push_back(x[j]);
		j = (j + 1) % n;
		if (j == xi) break;
	}
	for (int j = yi; ;) {
		if (y[j])b.push_back(y[j]);
		j = (j + 1) % n;
		if (j == yi) break;
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i] != b[i]) {
			puts("NO"); exit(0);
		}
	}
	puts("YES");


	return 0;
}