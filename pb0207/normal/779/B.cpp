#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n,k,cnt,tot,tmp;

int main()
{
	scanf("%d%d",&n,&k);
	while(n)
	{
		if(n%10==0)
			tmp++;
		else
			tot++,cnt+=tmp,tmp=0;
		if(cnt==k)
		{
			printf("%d",tot-1);
			return 0;
		}
		if(cnt+tmp==k)
		{
			printf("%d",tot);
			return 0;
		}
		n/=10;
	}
	printf("%d",max(cnt+tot-1,0));
}