#include <stdio.h>

#define LL long long

LL a, b, c, d;

int num_2(LL val) {
	int ans = 0;
	while(val%2 == 0) {
		ans++;
		val /= 2;
	}
	return ans;
}
int num_3(LL val) {
	int ans = 0;
	while(val%3 == 0) {
		ans++;
		val /= 3;
	}
	return ans;
}
int main() {
	scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &d);
	int cnt = 0;
	while(num_3(a*b) != num_3(c*d)) {
		if(num_3(a*b) > num_3(c*d)) {
			if(a%3 == 0) {
				a = 2*a/3;
			}else {
				b = 2*b/3;
			}
		}else {
			if(c%3 == 0) {
				c = 2*c/3;
			}else {
				d = 2*d/3;
			}
		}
		cnt++;
	}
	while(num_2(a*b) != num_2(c*d)) {
		if(num_2(a*b) > num_2(c*d)) {
			if(a%2 == 0) {
				a /= 2;
			}else {
				b /= 2;
			}
		}else {
			if(c%2 == 0) {
				c /= 2;
			}else {
				d /= 2;
			}
		}
		cnt++;
	}
	if(a*b != c*d) {
		printf("-1\n");
	}else {
		printf("%d\n%I64d %I64d\n%I64d %I64d\n", cnt ,a , b, c, d);
	}
	return 0;
}