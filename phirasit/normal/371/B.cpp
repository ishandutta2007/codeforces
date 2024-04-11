#include <stdio.h>

int a,b,c,d,e,x,y,z;

int abs(int k) {
	if(k < 0) return -k;
	return k;
}
int main() {
	scanf("%d %d",&a,&b);
	c = d = e = x = y = z = 0;
	while(a%2 == 0) {
		c++;
		a /= 2;
	}
	while(a%3 == 0) {
		d++;
		a /= 3;
	}
	while(a%5 == 0) {
		e++;
		a /= 5;
	}
	while(b%2 == 0) {
		x++;
		b /= 2;
	}
	while(b%3 == 0) {
		y++;
		b /= 3;
	}
	while(b%5 == 0) {
		z++;
		b /= 5;
	}
	if(a != b) {
		printf("-1\n");
	}else {
		printf("%d\n",abs(c-x) + abs(d-y) + abs(e-z));
	}
	return 0;
}