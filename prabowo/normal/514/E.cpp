#include <cstdio>

typedef long long LL;

const int MOD = 1000000007;

const int sz = 101;
struct Matrix {
	LL a[sz][sz];
	
	Matrix (int x = 0) {
		for (int i=0; i<sz; i++) 
			for (int j=0; j<sz; j++) 
				if (i ^ j) 
					a[i][j] = 0;
				else 
					a[i][j] = x;
	}
	
	Matrix operator * (const Matrix &other) const {
		Matrix ret;	
		for (int i=0; i<sz; i++) 
			for (int j=0; j<sz; j++)
				for (int k=0; k<sz; k++)
					ret.a[i][j] += a[i][k] * other.a[k][j],
					ret.a[i][j] %= MOD;
					
		return ret;
	}
	
	void operator *= (const Matrix &other) {
		*this = *this * other;
		return;
	}
	
	void print () {
		for (int i=0; i<sz; i++) {
			for (int j=0; j<sz; j++) printf ("%I64d ", a[i][j]);
			printf ("\n");
		}
	}
};

Matrix power (Matrix &x, int y) {
	Matrix mul = x;
	Matrix ret (1);
	
	while (y) {
		if (y & 1) ret *= mul;
		mul *= mul;
		y >>= 1;
	}
	
	return ret;
}

int main() {
	int n, x;
	scanf ("%d %d", &n, &x);
	
	int d;
	Matrix mul;
	for (int i=0; i<n; i++) {
		scanf ("%d", &d);
		mul.a[0][--d]++;
	}
	
	for (int i=0; i<99; i++)
		mul.a[i + 1][i] = 1;
		
	mul.a[100][100] = 1;
	mul.a[0][100] = 1;
		
	Matrix ans = power (mul, x);
	printf ("%I64d\n", (ans.a[0][0] + ans.a[0][100]) % MOD);
	
	return 0;
}