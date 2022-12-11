#include <stdio.h>
#include <math.h>

#define ESP 1e-15
#define ESP2 1e-7

int n, x, y;
int a;

int main() {
	scanf("%d%d%d", &n, &x, &y);
	while(n--) {
		scanf("%d", &a);
		a %= x + y;
		double bs_a = 0, bs_b = 1;
		while(bs_b - bs_a > ESP) {
			double bs_mid = (bs_a + bs_b) / 2;
			int val = floor(x * bs_mid) + floor(y * bs_mid);
			if(val >= a) {
				bs_b = bs_mid;
			}else {
				bs_a = bs_mid;
			}
		}
		double cx = x * bs_a, cy = y * bs_a;
		int ans_a = ceil(cx) - cx < ESP2 || cx - floor(cx) < ESP2;
		int ans_b = ceil(cy) - cy < ESP2 || cy - floor(cy) < ESP2;
		if(ans_a && ans_b) {
			printf("Both\n");
		}else if(ans_a) {
			printf("Vanya\n");
		}else {
			printf("Vova\n");
		}
	}
	return 0;
}