#include <stdio.h>
#include <string.h>
#define MX_N 100010

int x[MX_N],y[MX_N],z[MX_N];
char str[MX_N];
int n,m;

int main() {
	int i,j;
	scanf("%s",str);
	n = strlen(str);
	for(i=0;i < n;i++) {
		x[i] = x[i-1] + (str[i] == 'x');
		y[i] = y[i-1] + (str[i] == 'y');
		z[i] = z[i-1] + (str[i] == 'z');
	}
	scanf("%d",&m);
	while(m--) {
		int l,r;
		scanf("%d %d",&l,&r);
		r--;
		l--;
		int a = x[r] - x[l-1];
		int b = y[r] - y[l-1];
		int c = z[r] - z[l-1];
		if((a-b > 1 || b-c > 1 || a-c > 1 || b-a > 1 || c-b > 1 || c-a > 1) && r-l >= 2)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}