#include <stdio.h>

int n,a,b,c,d;
char str[100010];

int main() {
	int i;
	scanf("%d %d %d %d %d %s",&n,&a,&b,&c,&d,str);
	for(i=0;i<n;i++) {
		if(str[i] == 'E' && a < c)
			a++;
		if(str[i] == 'W' && a > c)
			a--;
		if(str[i] == 'N' && b < d)
			b++;
		if(str[i] == 'S' && b > d)
			b--;
		if(a == c && b == d) {
			printf("%d\n",i+1);
			break;
		}
	}
	if(a != c || b != d)
		printf("-1\n");
	return 0;
}