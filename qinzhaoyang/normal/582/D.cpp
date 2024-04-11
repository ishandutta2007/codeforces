#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 2010 , P = 1000000007;
int add(int x , int y) {return x + y >= P ? x + y - P : x + y;}
int sub(int x , int y) {return x < y ? x + P - y : x - y;}
int mul(int x , int y) {return 1ll * x * y % P;}

int p, al, a[N], n, x[4003], len, f[4010][4010][2][2], ans;
char A[N];

int main() {
	scanf("%d%d%s", &p, &al, A + 1) , n = strlen(A + 1);
	if(al > 4000) return printf("0\n") , 0;
	for(int i = 1; i <= n; i++) a[i] = A[n - i + 1] - '0';
	while(n) {
		long long t = 0;
		for(int i = n; i >= 1; i--) {
			t = t * 10 + a[i] , a[i] = t / p , t %= p;
			if(!a[i] && i == n) n--; 
		}
		x[++len] = t;
	}
	f[len + 1][0][0][1] = 1;
	for(int i = len; i >= 1; i--) {
		int c1 = 1ll * p * (p + 1) / 2 % P;
		int c2 = 1ll * x[i] * (x[i] + 1) / 2 % P;
		int c3 = 1ll * p * (p - 1) / 2  % P;
		int c4 = 1ll * x[i] * ((p << 1) - x[i] - 1) / 2 % P;
		int c5 = 1ll * x[i] * (x[i] - 1) / 2 % P;
		int c6 = 1ll * x[i] * ((p << 1) - x[i] + 1) / 2 % P;
		for(int j = 0; j <= len - i; j++) {
			int f0 = f[i + 1][j][0][0] , f1 = f[i + 1][j][0][1];
			int f2 = f[i + 1][j][1][0] , f3 = f[i + 1][j][1][1];
			f[i][j][0][0] = add(add(mul(c1 , f0) , mul(c2 , f1)) , add(mul(c3 , f2) , mul(c4 , f3)));
			f[i][j][0][1] = add(mul(x[i] + 1 , f1) , mul(p - x[i] - 1 , f3));
			f[i][j + 1][1][0] = add(add(mul(c3 , f0) , mul(c5 , f1)) , add(mul(c1 , f2) , mul(c6 , f3)));
			f[i][j + 1][1][1] = add(mul(x[i] , f1) , mul(p - x[i] , f3));
		}
	}
	for(int i = al; i < len; i++) ans = add(ans , add(f[1][i][0][0] , f[1][i][0][1]));
	printf("%d\n" , ans);
	return 0;
}