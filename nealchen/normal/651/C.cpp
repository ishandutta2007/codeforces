#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
struct ptt {
	int x, y;
} pt[200000];
bool px(ptt a, ptt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}
bool py(ptt a, ptt b) {
	return a.y < b.y || a.y == b.y && a.x < b.x;
}
int n;
int main() {
	int i, j;
	long long ans = 0;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) scanf("%d%d", &pt[i].x, &pt[i].y);
	std::sort(pt, pt + n, px);
	for(i=1,j=0; i < n; ++i) if(pt[i].x == pt[i-1].x && pt[i].y == pt[i-1].y)ans-=++j;else j=0;
	for(i=1,j=0; i < n; ++i) if(pt[i].x == pt[i-1].x)ans+=++j;else j=0;
	std::sort(pt, pt + n, py);
	for(i=1,j=0; i < n; ++i) if(pt[i].y == pt[i-1].y)ans+=++j;else j=0;
	printf("%I64d", ans);
	return 0;
}