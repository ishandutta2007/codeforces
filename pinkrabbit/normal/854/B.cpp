#include<cstdio>
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	if(k==n||k==0){puts("0 0");return 0;}
	printf("1 ");
	if(k*3ll<=n) printf("%d",2*k);
	else printf("%d",n-k);
	return 0;
}