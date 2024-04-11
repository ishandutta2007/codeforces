#include <cstdio>

int near (long long x) {
	x %= 360;
	if (x < 0)
		return x < -180 ? 360 + x : -x;
	return x > 180 ? 360 - x : x;
}

int main () {
	long long x;
	scanf ("%I64d", &x);
	
	int ans = 0;
	int mini = near(x);
	
	if (near (x - 90) < mini) {
		mini = near (x - 90);
		ans = 1;
	}
	if (near (x - 180) < mini) {
		mini = near (x - 180);
		ans = 2;
	}
	if (near (x - 270) < mini) {
		mini = near (x - 270);
		ans = 3;
	}
	
	return 0 * printf ("%d\n", ans);
}