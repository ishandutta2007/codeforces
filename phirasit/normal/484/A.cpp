#include <stdio.h>

#define LL long long

LL l, r;

LL next(LL val) {
	LL x = 1;
	while(x & val) {
		x <<= 1;
	}
	return val ^ x;
}
void evaluate(void) {
	scanf("%I64d%I64d", &l, &r);
	while(next(l) <= r) {
		l = next(l);
	}
	printf("%I64d\n", l);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		evaluate();
	}
	return 0;
}