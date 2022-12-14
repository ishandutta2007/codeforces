#include"bits/stdc++.h"
#include "chrono"
using namespace std;
typedef long long ll;

#define MAX 512

int n;
int m;
int r[MAX][MAX];
int R[MAX][MAX];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &r[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &R[i][j]);
			r[i][j] ^= R[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		int cn = 0;
		for (int j = 0; j < m; j++) {
			cn ^= r[i][j];
		}
		if (cn) {
			puts("No");
			return 0;
		}
	}
	for (int j = 0; j < m; j++) {
		int cn = 0;
		for (int i = 0; i < n; i++) {
			cn ^= r[i][j];
		}
		if (cn) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}