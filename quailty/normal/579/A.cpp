#include<cstdio>
int main()
{
	int x,ans=0;
	scanf("%d",&x);
	for(int i=0;(1<<i)<=x;i++)
        if(x&(1<<i))ans++;
	printf("%d\n",ans);
	return 0;
}