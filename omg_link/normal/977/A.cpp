#include <stdio.h>
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	while(k--)
		if(n%10!=0)n--;
		else n/=10;
	printf("%d",n);
}