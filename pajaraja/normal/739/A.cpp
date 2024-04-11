#include <iostream>
#include <stdio.h>
int main(int argc, char** argv) 
{
	int br=0,n,m,min,t1,t2;
	scanf("%d%d",&n,&m);
	min=n+6;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&t1,&t2);
		min=(t2-t1+1)>min?min:t2-t1+1;
	}
	printf("%d\n",min);
	for(int i=0;i<n;i++)
	{
		printf("%d ",br);
		br++;
		if(br==min) br=0; 
	}
	return 0;
}