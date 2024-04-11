#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string.h>
#define mp(a,b) make_pair((a),(b))
#define nextInt(n) scanf("%d",&(n))
#define F(i,n) for(int (i) = 0; (i) < n; (i)++)

using namespace std;

const int mod = 1000000007;


// returns (x,y) such that ax+by = gcd(a,b)
// suggested that a,b>=0, a^2+b^2>0
int axpby(int a, int b) {
	//a,b must be less than 2^30
	int xx = 1; int yy = 0; int dd = a;
	int x = 0; int y = 1; int d = b;
	while (d) {
		int q = dd / d;

		int tmp = d;
		d = dd - d*q;
		dd = tmp;

		tmp = x;
		x = xx - x*q;
		xx = tmp;

		tmp = y;
		y = yy - y*q;
		yy = tmp;
	}
	if (xx < 0)  xx += b;
	return xx;
}

int par[4001][4001];
int fact[4001];
int inv[4001];
int par2[4001];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= 4000; i++) {
		fact[i] = (long long)fact[i - 1] * i%mod;
		inv[i] = axpby(fact[i], mod);
	}
	int n;
	nextInt(n);
	par[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			par[i][j] = par[i - 1][j - 1];
			par[i][j] = ((long long)par[i][j] + (long long)j*par[i - 1][j]) % mod;
		}
	}
	for (int i = 0; i <= n; i++) {
		int sum = 0;
		for (int j = 0; j <= i; j++) {
			sum = ((long long)sum + par[i][j]) % mod;
		}
		par2[i] = sum;
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = fact[n];
		tmp = (long long)tmp*inv[i] % mod;
		tmp = (long long)tmp*inv[n - i] % mod;
		tmp = (long long)tmp*par2[n - i] % mod;
		res = ((long long)res + tmp) % mod;
	}
	printf("%d\n", res);
	return 0;
}