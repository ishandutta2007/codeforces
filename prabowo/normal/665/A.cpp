#include <cstdio>

int a, ta;
int b, tb;
int hh, mm;

int main () {
	scanf ("%d %d", &a, &ta);
	scanf ("%d %d", &b, &tb);
	scanf ("%d:%d", &hh, &mm);
	ta += tb - 1;
	
	int ans = 0;
	int cur = (hh - 5) * 60 + mm - tb + 1;
	while (ta--) {
		if (cur >= 0 && cur < 19 * 60)
			ans += cur % b == 0;			
			
		cur++;
	}
	
	printf ("%d\n", ans);
	return 0;
}