#include<cstdio>
int n, a, b, la, lb;
int main() {
    scanf("%d", &n);
    for (;n--;) {
	int t, x, y;
	scanf("%d%d%d", &t, &x, &y);
	if (t==1) {
	    a+=x;
	    la+=y;
	} else {
	    b+=x;
	    lb+=y;
	}
    }
    puts(a<la?"DEAD":"LIVE");
    puts(b<lb?"DEAD":"LIVE");
    return 0;
}