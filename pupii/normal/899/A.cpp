#include<cstdio>
int main(){
	int a=0,b=0,k,n;
	scanf("%d",&n);
	while(n--)scanf("%d",&k),k==1?++a:++b;
	if(a<=b)printf("%d\n",a);
	else printf("%d\n",b+(a-b)/3);
	return 0;
}