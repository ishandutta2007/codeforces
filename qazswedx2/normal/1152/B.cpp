#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int x,n,len=0,a[105],at,t;
int main()
{
	scanf("%d",&x);
	n=1;
	while(n<=x) n<<=1;
	for(int i=30;i>0;i--)
		if((1<<i)<=x&&((1<<i-1)&x)==0)
		{
			x^=((1<<i)-1);
			a[++at]=i;
			t++;
			//printf("i=%d,x=%d,n=%d\n",i,x,n);
			if(x+1==n) break;
			x++;
			t++;
		} 
	printf("%d\n",t);
	for(int i=1;i<=at;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}