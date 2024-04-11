#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int prime[1000005],pt,p[1000005],ans[1000005],n;
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		if(!p[i])
		{
			prime[++pt]=i;
			ans[i]=pt;
		}
		for(int j=1;j<=pt&&i*prime[j]<=n;j++)
		{
			p[i*prime[j]]=1;
			ans[i*prime[j]]=j;
			if(i%prime[j]==0) break;
		} 
	}
	for(int i=2;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}