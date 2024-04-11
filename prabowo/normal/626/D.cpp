#include <cstdio>
#include <cstdlib>

int n;
int a[2002];
int dif[5002];


int main () {
	scanf ("%d", &n);
	for (int i=0; i<n; i++) {
		scanf ("%d", a + i);
		for (int j=0; j<i; j++) 
			dif[ abs(a[i] - a[j]) ]++;
	}
	
	for (int i=5000-1; i; i--) 
		dif[i - 1] += dif[i];
	
	long long cnt = 0;
	for (int i=0; i<5000; i++) {
		for (int j=0; j<5000; j++) {
			if (i + j >= 5000) break;
			
			cnt += (long long) (dif[i] - dif[i + 1]) * (dif[j] - dif[j + 1]) * dif[i + j + 1];
		}
	}
	
	double ans = cnt;
	ans *= 8;
	for (int i=0; i<3; i++) ans /= n * (n - 1);
	printf ("%.10lf\n", ans);
	
	return 0;
}