#include <cstdio>

int main () {
	int h, m;
	long long a;
	
	scanf ("%d:%d", &h, &m);
	scanf ("%I64d", &a);
	
	long long t = a + h * 60 + m;
	
	printf ("%02I64d:%02I64d\n", t / 60 % 24, t % 60);
	
	return 0;
}