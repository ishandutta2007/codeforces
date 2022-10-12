#include <cstdio>
#include <cstring>

typedef long long LL;

const int MOD = 1000000007;

struct Mat {
	LL a[102][102];
	int sz;
	
	Mat () { memset (a, 0, sizeof a), sz = 0; }
	
	Mat operator * (const Mat &other) const {
		Mat ret;
		ret.sz = sz;
		for (int i=0; i<sz; i++) for (int j=0; j<sz; j++) for (int k=0; k<sz; k++) 
			ret.a[i][j] += a[i][k] * other.a[k][j],
			ret.a[i][j] %= MOD;
			
		return ret;
	}
	
	void print () {
		for (int i=0; i<sz; i++) {
			for (int j=0; j<sz; j++) printf ("%I64d ", a[i][j]);
			printf ("\n");
		} return;
	}
};

Mat power (Mat x, int y) {
	if (y == 0) {
		Mat ret;
		ret.sz = x.sz;
		for (int i=0; i<x.sz; i++) ret.a[i][i] = 1;
		return ret;
	}
	
	return y & 1 ? x * power (x * x, y >> 1) : power (x * x, y >> 1);
}

int main () {
	int n, b, k, x;
	scanf ("%d %d %d %d", &n, &b, &k, &x);
	
	int cnt[10] = {};
	for (int i=0; i<n; i++) {
		int a;
		scanf ("%d", &a);
		cnt[a]++;
	}
	
	Mat mul; mul.sz = x;	
	for (int i=0; i<x; i++) 
		for (int j=1; j<10; j++) 
			mul.a[i][(i * 10 + j) % x] += cnt[j];
	// mul.print();
	
	printf ("%I64d\n", power (mul, b).a[0][k]);
	// power (mul, b).print();
	
	return 0;
}