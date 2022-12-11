#include <stdio.h>

int main() {
	int a,b,x,y,z;
	scanf("%d %d",&a,&b);
	x = y = z = 0;
	for(int i=1;i<7;i++) {
		int k = a-i;
		if(k < 0) k = -k;
		int j = b-i;
		if(j < 0) j = -j;
		if(k < j) x++;
		else if(k > j) z++;
		else y++;
	}
	printf("%d %d %d\n",x,y,z);
	return 0;
}