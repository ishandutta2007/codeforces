#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, a[N], f[N], qz[N];
int g[N];
int get(int x, int y) { 
	return qz[x] ^ qz[y];
} 
int main() {
	scanf("%d", &n);
	L(i, 1, n - 1) {
		printf("XOR %d %d\n", i, i + 1);
		fflush(stdout);
		scanf("%d", &qz[i + 1]);
	}
	g[0] = 1;
	L(i, 2, n) qz[i] ^= qz[i - 1];
	L(i, 2, n) {
		if(g[qz[i]]) {
			printf("OR %d %d\n", g[qz[i]], i);
			fflush(stdout);
			int k; scanf("%d", &k);
			a[i] = k;
			L(j, 1, n) a[j] = (a[i] ^ get(i, j));
			printf("!");
			L(j, 1, n) printf(" %d", a[j]); 
			printf("\n");
			fflush(stdout);
			return 0;
		}
		g[qz[i]] = i;
	}
	L(i, 1, n) if(qz[i] == n - 1) {
		int now = 2 + (i == 2);
		int sum1 = n - 1, sum2, sum3;
		printf("AND 1 %d\n", now);
		fflush(stdout);
		int k; scanf("%d", &k), sum2 = k * 2 + get(1, now);
		printf("AND %d %d\n", i, now);
		fflush(stdout);
		scanf("%d", &k), sum3 = k * 2 + get(i, now);
		a[1] = (sum1 + sum2 - sum3) / 2;
		L(j, 2, n) a[j] = (a[1] ^ get(1, j));
		printf("!");
		L(j, 1, n) printf(" %d", a[j]); 
		printf("\n");
		fflush(stdout);
		return 0;
	}
	return 0;
}