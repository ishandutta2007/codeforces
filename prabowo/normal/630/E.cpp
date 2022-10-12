#include <cstdio>
#include <algorithm>

int main () {
	long long x, y, xx, yy;
	scanf ("%I64d %I64d %I64d %I64d", &xx, &yy, &x, &y);
	
	const int plus = 1000000002;
	xx += plus;
	yy += plus;
	x += plus;
	y += plus;
	
	long long cnt1, cnt2;

	cnt2 = (y - yy) / 2 + 1;
	cnt1 = (y - yy + 1) / 2;	

	printf ("%I64d\n", cnt1 * ((x - xx) / 2) + cnt2 * ((x - xx) / 2) + cnt2);
	
	return 0;
}