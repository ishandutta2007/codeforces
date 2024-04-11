#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair
const int N = 35;
int n, m, a[N][N], get[N], p[N], maxn;
int getans() {
	int sum = 0;
	L(i, 1, n) sum += (p[i] == 1 ? -a[i][m] : a[i][m]); 
	L(j, 1, m - 1) {
		// p[m][j] = 0
		int suma = a[m][j] + (p[m] == 0 ? a[m][j + m] : - a[m][j + m]); 
		L(i, 1, m - 1) {
			if(p[i] == 0) suma += abs(a[i][j] + a[i][j + m] + a[i + m][j] + (p[m] == 0 ? a[i + m][j + m] : -a[i + m][j + m]));
			else suma += abs(a[i][j] - a[i][j + m] + a[i + m][j] + (p[m] == 1 ? a[i + m][j + m] : -a[i + m][j + m]));
		}
		// p[m][j] = 1
		int sumb = -a[m][j] + (p[m] == 1 ? a[m][j + m] : - a[m][j + m]); 
		L(i, 1, m - 1) {
			if(p[i] == 0) sumb += abs(a[i][j] + a[i][j + m] - a[i + m][j] + (p[m] == 1 ? a[i + m][j + m] : -a[i + m][j + m]));
			else sumb += abs(a[i][j] - a[i][j + m] - a[i + m][j] + (p[m] == 0 ? a[i + m][j + m] : -a[i + m][j + m]));
		}
		sum += max(suma, sumb);
	}
	return sum;
}
int main() {
	scanf("%d", &n);
	L(i, 1, n) L(j, 1, n) scanf("%d", &a[i][j]);
	m = (n + 1) / 2;
	L(i, 0, (1 << m) - 1) {
		L(j, 1, m) p[j] = ((i >> (j - 1)) & 1);
		L(j, m + 1, n) p[j] = (p[m] ^ p[j - m]);
		maxn = max(maxn, getans());
	}
	printf("%d\n", maxn);
	return 0;
}