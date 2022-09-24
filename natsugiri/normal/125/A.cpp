#include<cstdio>

int main(){
	int n,i,f;
	scanf("%d",&n);
	i=n/3;
	n-=i*3;
	if(n==2)i++;
	f=i/12;
	i-=f*12;
	printf("%d %d\n",f,i);
}